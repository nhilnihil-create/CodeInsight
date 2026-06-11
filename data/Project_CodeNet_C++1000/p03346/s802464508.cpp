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

    vl v(n);
    rep(i, n) {
        ll p;
        cin >> p;
        v[p-1] = i;
    }

    ll now = 0;
    ll ma = 0;
    ll t = -1;
    rep(i, n) {
        if(t < v[i]) {
            now++;
        }
        else {
            chmax(ma, now);
            now = 1;
        }
        t = v[i];
    }
    chmax(ma, now);

    out(n - ma);
    re0;
}