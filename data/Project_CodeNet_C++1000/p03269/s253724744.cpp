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
    ll L;
    cin >> L;

    ll r = 0;
    vl p(21);  // p[i] : 2のi乗
    p[0] = 1;
    exrep(i, 1, 20) {
        p[i] = 2*p[i-1];
        if(L < p[i]) {
            break;
        }
        r++;
    }

    vector<tuple<ll, ll, ll>> v;
    exrep(i, 1, r) {
        v.emplace_back(i, i+1, 0);
        v.emplace_back(i, i+1, p[i-1]);
    }
    for(ll i = r; i >= 1; i--) {
        if(L - p[i-1] >= p[r]) {
            v.emplace_back(i, r+1, L - p[i-1]);
            L -= p[i-1];
        }
    }

    cout << r+1 << " " << v.size() << "\n";
    for(auto x : v) {
        cout << get<0>(x) << " " << get<1>(x) << " " << get<2>(x) << "\n"; 
    }

    re0;
}