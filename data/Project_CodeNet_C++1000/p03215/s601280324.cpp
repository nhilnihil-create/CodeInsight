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

#define int long long

signed main() {
    int n, k; cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<ll> v;

    for (int i = 0; i < n; i++) {
        ll s = 0;
        for (int j = i; j < n; j++) {
            s += a[j];
            v.eb(s);
        }
    }

    bool check[v.size() + 1];
    int num = 0;
    for (int i = 0; i < v.size(); i++) check[i] = true;

    for (int i = 50; i > 0; i--) {
        num = 0;
        for (int j = 0; j < v.size(); j++) {
            if (check[j]) {
                if ((v[j] >> i) & 1) num++;
            }
        }
        if (num >= k) {
            for (int j = 0; j < v.size(); j++) {
                if (check[j]) {
                    if (!((v[j] >> i) & 1)) check[j] = false;
                }
            }
        }
    }
    ll ans = LLONG_MAX;
    for (int i = 0; i < v.size(); i++) {
        if (check[i]) ans &= v[i];
    }
    cout << ans;
}
