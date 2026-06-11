#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
typedef long long ll;

vector<pair<char,int> > rfe_tuple(string S){
  vector<pair<char,int> > ff;
  int sum=1;
  for (int i=1;i<S.length();i++){
    while(S[i]==S[i-1]){
      sum++;
      i++;
    }
    ff.push_back(make_pair(S[i-1],sum));
    sum=1;
  }
  if(S[S.length()-1]!=S[S.length()-2]) ff.push_back(make_pair(S[S.length()-1],1));
  return ff;
}

int main(){
  string S;
  int N,K;
  cin >> N >> K;
  cin >> S;
  vector<pair<char,int> > f;
  f=rfe_tuple(S);

  vector<int> sum(f.size() + 1);
  for (int i = 0; i < f.size(); ++i) {
    sum[i + 1] = sum[i] + f[i].second;
  }
  int ans = 0;
  for (int i = 0; i < f.size(); ++i) {
    int ptr = min(i + 2 * K + (f[i].first-'0'), int(f.size()));
    ans = max(ans, sum[ptr] - sum[i]);
  }
  cout << ans << endl;
}
