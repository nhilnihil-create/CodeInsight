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
  ll N;
  cin >> N;
  string S;
  cin >> S;

  map<char, ll> max_pos;
  rep(i, N) max_pos[S[i]] = i;

  ll ans = -1;
  
  rep(i, N){
    vl alph(26, 0);
    ll cnt = 0;
    
    rep(j, i + 1){
      if(alph[S[j] - 'a'] == 1) continue;
      if(max_pos[S[j]] >= i + 1) alph[S[j] - 'a'] = 1;
    }

    rep(i, 26) cnt += alph[i];

    ans = max(ans, cnt);
  }

  cout << ans << endl;
  
  return 0;
}
