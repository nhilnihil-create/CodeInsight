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

ll x, y;

int main() {
    pyshnapyshnakaa
    ll q, w, e, a, b, c;
    cin >> n >> m >> k;
    string s1, s2;
    cin >> x >> y;
    x--; y--;
    cin >> s1 >> s2;
    ll mn = m, mx = -1;
    for (q = s1.size() - 1; q >= 0; q--) {
        ll d1 = 0, d2 = 0;
        if (s1[q] == 'L') {
            d1 = -1;
        }
        if (s1[q] == 'R') {
            d1 = 1;
        }
        if (s2[q] == 'L') {
            d2 = -1;
        }
        if (s2[q] == 'R') {
            d2 = 1;
        }
        if (d2 == -1) {
            mn++;
            mn = min(m, mn);
        }
        if (d2 == 1) {
            mx--;
            mx = max(-1LL, mx);
        }
        if (d1 == 1) {
            mn--;
        }
        if (d1 == -1) {
            mx++;
        }
        // cout << "D " << d1 << " " << d2 << endl;
        // cout << q << " " << mn << " " << mx << endl;
        // if (d1 == 1) {
        //     mn = min(mn, n - 1);
        // }
        // if (d1 == -1) {
        //     mx = max(mx, 0LL);
        // }
        if (mx >= mn - 1) {
            cout << "NO";
            return 0;
        }
    }
    if (mn <= y || mx >= y) {
        cout << "NO";
        return 0;
    }
    // cout << "FIRST PASSED" << endl;
    mn = n, mx = -1;
    for (q = s1.size() - 1; q >= 0; q--) {
        ll d1 = 0, d2 = 0;
        if (s1[q] == 'U') {
            d1 = -1;
        }
        if (s1[q] == 'D') {
            d1 = 1;
        }
        if (s2[q] == 'U') {
            d2 = -1;
        }
        if (s2[q] == 'D') {
            d2 = 1;
        }
        if (d2 == -1) {
            mn++;
            mn = min(mn, n);
        }
        if (d2 == 1) {
            mx--;
            mx = max(mx, -1LL);
        }
        if (d1 == 1) {
            mn--;
        }
        if (d1 == -1) {
            mx++;
        }
                // cout << q << " " << mn << " " << mx << endl;

        if (mx >= mn - 1) {
            cout << "NO";
            return 0;
        }
    }
    if (mn <= x || mx >= x) {
        cout << "NO";
        return 0;
    }
    cout << "YES";
    return 0;
}