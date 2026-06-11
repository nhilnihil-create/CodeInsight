#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
const ll mod = 1000000007;
const ll INF = 9223372036854775807;
#define Sort(a) sort(a.begin(), a.end())
#define Reverse(a) reverse(a.begin(), a.end())
#define Pi acos(-1)

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << setprecision(15) << fixed;
  ll n;
  cin >> n;
  vector<tuple<string,ll,ll>> a(n);
  rep(i,n) {
    string s;
    ll p;
    cin >> s >> p;
    a[i] = tuple(s,-1*p,i+1);
  }
  Sort(a);
  rep(i,n) {
    cout << get<2>(a[i]) << '\n'; 
  }
}