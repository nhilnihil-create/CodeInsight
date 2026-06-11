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
  ll N, H;
  cin >> N >> H;
  vl a(N), b(N);
  rep(i, N) cin >> a[i] >> b[i];

  stable_sort(a.begin(), a.end());
  stable_sort(b.begin(), b.end());

  ll amax = a[N - 1];
  ll cnt = (ll)(b.end() - upper_bound(b.begin(), b.end(), amax));

  if(cnt == 0){
    cout << (H / amax) + (H  % amax > 0 ? 1 : 0) << endl;
    return 0;
  }

  ll damage = 0;

  rep_inv(i, N - 1, N - cnt - 1){
    damage += b[i];
    if(damage >= H){
      cout << N - i << endl;
      return 0;
    }
  }

  H -= damage;
  cnt += (H / amax) + (H % amax > 0 ? 1 : 0);

  cout << cnt << endl;
  
  return 0;
}
