#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vb = vector<bool>;
using vc = vector<char>;
using vs = vector<string>;
using vvi = vector<vector<int>>;
using vvc = vector<vector<char>>;
using pii = pair<int, int>;
#define fix10 cout << fixed << setprecision(10);
#define rep(i,n) for(int i=0; i<(int)(n);i++)
#define MOD 1000000007

int main(){
  int n;
  cin >> n;
  vector<int> clr(n);
  rep(i,n) cin >> clr.at(i);
  vector<long> dp(n+1,0);
  vector<long> hs(200001,0);
  dp.at(0) = 1;
  hs.at(clr.at(0)) = 1;
  for(int i=1;i<=n;i++){
    int c = clr.at(i-1);
    if(i != n){
      if(clr.at(i-1) == clr.at(i)) continue;
    }
    dp.at(i) = hs.at(c) % MOD;
    if(i == n) continue;
    hs.at(clr.at(i)) += dp.at(i);
    hs.at(clr.at(i)) %= MOD;
  }
  cout << dp.at(n) % MOD << endl;
}