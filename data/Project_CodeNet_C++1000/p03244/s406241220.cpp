#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>
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
const double pi = acos(-1);

int main() {
    ll n;
    cin >> n;
    ll m = n/2;

    vl a(n);
    rep(i, n) {
        cin >> a[i];
    }

    vl b(m);
    for(ll i = 0; i < n; i += 2) {
        b[i/2] = a[i];
    }
    vl c(m);
    for(ll i = 1; i < n; i += 2) {
        c[i/2] = a[i];
    }

    vl vb(100010);
    rep(i, m) {
        vb[b[i]]++;
    }
    vl vc(100010);
    rep(i, m) {
        vc[c[i]]++;
    }

    ll mab = 0;
    ll idb = 0;
    rep(i, 100010) {
        if(mab < vb[i]) {
            mab = vb[i];
            idb = i;
        }
    }
    ll mac = 0;
    ll idc = 0;
    rep(i, 100010) {
        if(mac < vc[i]) {
            mac = vc[i];
            idc = i;
        }
    }
    sort(rall(vb));
    sort(rall(vc));

    if(idb == idc) {
        out(n - max(vb[1] + vc[0], vb[0] + vc[1]));
    }   
    else {
        out(n - (vb[0] + vc[0]));
    }

    re0;
}