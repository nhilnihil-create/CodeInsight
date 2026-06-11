#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define REP(i,n) for(int i=0; i < (n); ++i)
#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)

#define INF 1e9

int cost[] = {2, 5, 5, 4, 5, 6, 3, 7, 6};

string comp(string a, string b){
  string ans = a;
  if(a.size() < b.size()){
    ans =b;
  }
  else if(a.size() == b.size()){
    if(a < b){
      ans = b;
    }
  }
  return ans;
}
int main(){
  int N, M;
  cin >> N >> M;
  vector<int> A(M);
  REP(i, M){
    cin >> A[i];
  }
  vector<string> dp(10020, "*");
  dp[0] = "";
  REP(i, N){
    if(dp[i] == "*") continue;
    REP(j, A.size()){
      dp[i+cost[A[j]-1]] = comp(dp[i+cost[A[j]-1]], dp[i]+char(A[j]+'0'));
    }
  }
  cout << dp[N] << endl;
  return 0;
}
