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

ll n, m, k, t;

int main() {
    pyshnapyshnakaa
    ll q, w, e, a, b, c;
    cin >> n;
    // cout << n * (n - 1) / 2 << endl;
    vector <pll> ANS;
    if (n % 2 == 0) {
        for (q = 0; q < n; q++) {
            for (w = q + 1; w < n; w++) {
                if (q + w != n - 1) {
                    ANS.pb(mp(q, w));
                    // cout << q + 1 << " " << w + 1 << endl;
                }
            }
        }
    }
    else {
        for (q = 0; q < n - 1; q++) {
            ANS.pb(mp(q, n - 1));
        }
        for (q = 0; q < n - 1; q++) {
            for (w = q + 1; w < n - 1; w++) {
                if (q + w + 2 != n) {
                    ANS.pb(mp(q, w));
                }
            }
        }
    }
    cout << ANS.size() << endl;
    for (auto p : ANS) {
        cout << p.first + 1 << " " << p.second + 1 << endl;
    }
    return 0;
}
