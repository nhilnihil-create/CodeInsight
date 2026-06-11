#include <bits/stdc++.h>
#define pb push_back
#define pll pair <ll, ll>
#define mp make_pair
#define pyshnapyshnakaa ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define x first
#define y second
#pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
#define plll pair <pair <ll, ll>, ll>
#define pllll pair <pair <ll, ll>, pair <ll, ll> >
#define psl pair <string, ll>
#define pld pair <ld, ld>
#define all(a) a.begin(), a.end()
#define vvl vector <vector <ll> >
#define cld complex <double>

typedef long long ll;

typedef long double ld;

using namespace std;

const ll maxn = 1e6 + 100;
const ll inf = 1e9;

ll n, m, k, t;

vector <ll> V[maxn];

ll H[maxn];

void dfs(ll v, ll p) {
    if (v != p) {
        H[v] = H[p] + 1;
    }
    for (auto v1 : V[v]) {
        if (v1 == p) {
            continue;
        }
        dfs(v1, v);
    } 
}

int main() {
    pyshnapyshnakaa
    ll q, w, e, a, b, c;
    cin >> n;
    for (q = 0; q < n - 1; q++) {
        cin >> a >> b;
        a--; b--;
        V[a].pb(b);
        V[b].pb(a);
    }
    dfs(0, 0);
    ll mx = 0, mxi = 0;
    for (q = 0; q < n; q++) {
        if (H[q] > mx) {
            mx = H[q];
            mxi = q;
        }
    }
    for (q = 0; q < n; q++) {
        H[q] = 0;
    }
    dfs(mxi, mxi);
    mx = 0;
    for (q = 0; q < n; q++) {
        mx = max(mx, H[q]);
    }
    mx++;
    // cout << mx << " MX" << endl;
    if (mx % 3 != 2) {
        cout << "First";
        return 0;
    }
    cout << "Second";
    return 0;
}