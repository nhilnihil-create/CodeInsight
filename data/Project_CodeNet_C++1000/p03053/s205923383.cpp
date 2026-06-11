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

const ll maxn = 1e3 + 100;
const ll inf = 1e9;

ll n, m, k, t;

string S[maxn];

ll D[maxn][maxn];

bool in(ll x, ll y) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

int main() {
    pyshnapyshnakaa
    ll q, w, e, a, b, c;
    cin >> n >> m;
    for (q = 0; q < n; q++) {
        cin >> S[q];
    }
    queue <pll> Q;
    for (q = 0; q < n; q++) {
        for (w = 0; w < m; w++) {
            if (S[q][w] == '#') {
                Q.push(mp(q, w));
                D[q][w] = 0;
            }
            else {
                D[q][w] = inf;
            }
        }
    }
    vector <pll> diff = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    while (!Q.empty()) {
        pll p = Q.front();
        Q.pop();
        ll x = p.first, y = p.second;
        for (auto d : diff) {
            ll nx = x + d.first;
            ll ny = y + d.second;
            if (!in(nx, ny)) {
                continue;
            }
            if (D[nx][ny] == inf) {
                Q.push(mp(nx, ny));
                D[nx][ny] = D[x][y] + 1;
            }
        }
    }
    ll ans = 0;
    for (q = 0; q < n; q++) {
        for (w = 0; w < m; w++) {
            ans = max(ans, D[q][w]);
        }
    }
    cout << ans;
    return 0;
}