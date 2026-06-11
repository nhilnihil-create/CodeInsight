#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1000000007;
const ll INF = 9223372036854775807;
#define Sort(a) sort(a.begin(), a.end())
#define Bsort(a) sort(a.begin(), a.end(), greater<ll>())
#define Pi acos(-1)

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  ll n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  vector<ll> a(n);
  for (ll i = 1; i < n; i++) {
    if(s[i] == 'C' && s[i-1] == 'A') {
      a[i] = a[i-1]+1;
    }
    else {
      a[i] = a[i-1];
    }
  }
  for (ll i = 0; i < m; i++) {
    ll l, r;
    cin >> l >> r;
    ll cnt = a[r-1] - a[l-1];
    cout << cnt << '\n';
  }
}