#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define REP(i,n) for(int i=0; i < (n); ++i)
#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)

#define INF 1e9

int cost[] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
string dp[100009]={};

string cmp(string a, string b){
  if(a.size() > b.size()){
    return a;
  }
  else if(a.size() < b.size()){
    return b;
  }
  else{
    return max(a, b);
  }
}

int main(){
  int N, M;
  cin >> N >> M;
  vector<int> A(M);
  REP(i, M){
    cin >> A[i];
  }
  REP(i, 100009){
    dp[i] = "*";
  }
  dp[0] = "";
  REP(i, N-1){
    if(dp[i] == "*") continue;
    REP(j, M){
      if(i+cost[A[j]] > N) continue;
      dp[i+cost[A[j]]] = cmp(dp[i+cost[A[j]]], dp[i]+to_string(A[j]));
    }
  }
  cout << dp[N] << endl;
  return 0;
}
