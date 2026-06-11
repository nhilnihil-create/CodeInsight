#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
#pragma GCC optimize ("-O3")
using namespace std; void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }

void _main() {
  ll N, P;
  cin >> N >> P;

  unordered_map<ll,ll> mp;
  for (ll i=2; i*i<=P; i++) {
    while (0==P%i) {
      mp[i]++;
      P /= i;
    }
  }
  if (1!=P) mp[P]++;

  ll ans=1;
  fore(i, mp) {
    ll a=i.second/N;
    for (ll j=0; j<a; j++) ans*=i.first;
  }
  cout << ans << "\n";
}