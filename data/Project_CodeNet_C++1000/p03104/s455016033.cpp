#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;

#define ll long long
#define ld long double
#define fi first
#define se second
#define sz(x) x.size()
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(x) begin(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define rep(i, x, n) for (ll i = x; i < n; i++)
#define fastio() ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0)
#define endl '\n'

typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;

template <class T> inline T RD(T &a) {T x; cin >> x; return a = x;}
template <class T> T gcd(T a, T b) {if (b) return gcd(b, a % b); else return a;}
template <class T> T lcm(T a, T b) {return (a * b) / gcd(a,b);}

signed main() {
    ll a, b; cin >> a >> b;
    ll ans = 0;
    for (ll i = a; i % 4 != 0; i++) {
        ans ^= i;
    }
    for (ll i = b; i % 4 != 0; i--) {
        b--;
        ans ^= i;
    }
    ans ^= b;
    cout << ans;
}
