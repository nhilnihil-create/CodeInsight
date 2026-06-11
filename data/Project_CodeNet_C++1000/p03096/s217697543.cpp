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
const ll mod = 1e9 + 7;

ll n, m, k, t;

ll A[maxn];

ll D[maxn];

ll last[maxn];

vector <ll> I[maxn];

int main() {
    pyshnapyshnakaa
    ll q, w, e, a, b, c;
    cin >> n;
    for (q = 0; q < n; q++) {
        cin >> A[q];
        if (!I[A[q]].empty()) {
            last[q] = I[A[q]].back();
        }
        else {
            last[q] = -1;
        }
        I[A[q]].pb(q);
    }
    D[0] = 1;
    for (q = 1; q < n; q++) {
        D[q] = D[q - 1];
        ll i = last[q];
        if (i == -1 || i == q - 1) {
            continue;
        }
        D[q] += D[i];
        D[q] %= mod;
    }
    cout << D[n - 1];
    return 0;
}
