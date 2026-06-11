#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define REP(i, n) for(int (i) = 0; (i) < (n); ++(i))
#define REPR(i, n) for(int (i) = (n); (i) >= 0; --(i))
#define FOR(i, n, m) for(int (i) = (n); (i) < (m); ++(i))

constexpr int INF = 1e9;
//constexpr ll INF = 1LL<<61;
constexpr ll mod = 1e9+7;
constexpr int MAXN = 1e4+10;
vector<string> dp(MAXN);
int cost[] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
bool cmp(string& a, string& b){
  if(a.size() != b.size()){
    return a.size() > b.size();
  }
  else{
    return a > b;
  }
}
string maxs(string& a, string& b){
  if(a=="?" || a==""){
    return b;
  }
  if(cmp(a, b)){
    return a;
  }
  else{
    return b;
  }
}
int main(){
  int N, M;
  cin >> N >> M;
  vector<int> A(M);
  REP(i, M){
    cin >> A[i];
  }
  REP(i, MAXN){
    dp[i] = "?";
  }
  dp[0] = "";
  REP(i, N){
    if(dp[i] == "?") continue;
    for(auto a : A){
      string s = dp[i] + to_string(a);
      dp[i+cost[a]] = maxs(dp[i+cost[a]], s);
    }
  }
  cout << dp[N] << endl;
  return 0;
}
