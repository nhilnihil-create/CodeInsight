#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<long long> A(1<<N);
  for(int i = 0; i < (1<<N); ++i) cin >> A[i];
  vector<long long> dp(1<<N,0), M(1<<N,0);
  for(int i = 1; i < (1<<N); ++i){
    // vector<long long> tmp;
    set<int> s;
    for(int j = 0; j < N; ++j){
      if(!(i>>j&1)) continue;
      int i_ = i^(1<<j);
      dp[i] = max(dp[i],dp[i_]);
      // tmp.push_back(A[i_]);
      // tmp.push_back(M[i_]);
      s.insert(M[i_]);
    }
    M[i] = i;
    vector<long long> tmp;
    for(auto e : s){
      if(A[e] > A[M[i]])
        M[i] = e;
      tmp.push_back(A[e]);
    }
    tmp.push_back(A[i]);
    sort(tmp.rbegin(), tmp.rend());
    if(tmp.size() < 2) continue;
    dp[i] = max(dp[i],tmp[0]+tmp[1]);
    dp[i] = max(dp[i],dp[i-1]);
  }
  for(int i = 1; i < (1<<N); ++i)
    cout << dp[i] << endl;
}
