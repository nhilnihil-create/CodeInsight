#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
using ll = long long;
using namespace std;

const long long MOD = 1000000007;
const ll LINF = 1LL << 50;

ll N;
int ketamax = 10;
ll ans = 0;


bool thisIs753num(string S){
  int s = S.size();
  bool f7 = false;
  bool f5 = false;
  bool f3 = false;

  REP(n,s){
    if (S[n] == '3') f3 = true;
    if (S[n] == '5') f5 = true;
    if (S[n] == '7') f7 = true;
  }

  if (f3 && f5 && f7){
    return true;
  } else{
    return false;
  }
}

void solve(int n, string S){
  if (thisIs753num(S)){
    ll num = stol(S);
    if (N >= num){
      //cout << num << endl;
      ans += 1;
    }
  }

  if (n <= ketamax){
    solve(n+1, "3"+S);
    solve(n+1, "5"+S);
    solve(n+1, "7"+S);
  }
}

int main() {
  cin >> N;
  solve(1,"3");
  solve(1,"5");
  solve(1,"7");

  cout << ans << endl;
}
