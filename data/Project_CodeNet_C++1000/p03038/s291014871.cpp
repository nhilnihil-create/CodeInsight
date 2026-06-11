#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
const int MOD = 1000000007;

void solve() {
  ll n, m;
  cin >> n >> m;
  vector<pair<ll, ll>> v;

  rep(i,n) {
    ll a;
    cin >> a;
    v.push_back(make_pair(a, 1));
  }
  rep(i,m) {
    ll b, c;
    cin >> b >> c;
    v.push_back(make_pair(c, b));
  }

  sort(v.begin(), v.end(), greater<>());
  ll ans = 0;
  ll count = 0;
  ll i = 0;

  while (count < n) {
    if (v[i].second <= n - count) {
      ans += v[i].second * v[i].first;
      count += v[i].second;
    } else {
      ans += (n - count) * v[i].first;
      count = n;
    }
    i++;
  }
  cout << ans << endl;
}

int main() {
  solve();
  return 0;
}