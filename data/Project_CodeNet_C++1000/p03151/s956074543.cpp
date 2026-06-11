#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <functional>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define exrep(i, a, b) for(ll i = a; i <= b; i++)
#define out(x) cout << x << endl
#define exout(x) printf("%.10f\n", x)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define re0 return 0
const ll mod = 1000000007;
const ll INF = 1e16;
const ll MAX_N = 100010;

int main() {
    ll n;
    cin >> n;

    vl a(n);
    ll sumA = 0;
    rep(i, n) {
        cin >> a[i];
        sumA += a[i];
    }

    vl b(n);
    ll sumB = 0;
    rep(i, n) {
        cin >> b[i];
        sumB += b[i];
    }

    if(sumA < sumB) {
        out(-1);
        re0;
    }

    ll u = 0;
    ll ans = 0;
    rep(i, n) {
        if(a[i] < b[i]) {
            u += b[i] - a[i];
            ans++;
        }
    }

    vl c(n);
    rep(i, n) {
        c[i] = a[i] - b[i];
    }
    sort(rall(c));

    ll cnt = 0;
    rep(i, n) {
        if(u <= cnt) {
            out(ans);
            re0;
        }
        cnt += c[i];
        ans++;
    }



    re0;
}