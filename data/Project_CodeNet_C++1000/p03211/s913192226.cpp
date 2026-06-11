#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep2(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define rep_inv(i, n, m) for(int i = (int)(n); i > (int)(m); i--)
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vc = vector<char>;
using vvl = vector<vl>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

int main(){
  string S;
  cin >> S;

  ll N = S.size();
  ll ans = 10000;

  rep(i, N - 2){
    ll val = 100*(S[i] - '0') + 10*(S[i+1] - '0') + (S[i+2] - '0');
    ans = min(ans, abs(val - 753));
  }

  cout << ans << "\n";
  
  return 0;
}
