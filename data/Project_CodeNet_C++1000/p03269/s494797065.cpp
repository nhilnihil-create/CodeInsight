#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    int x = 1, p;
    for (p = 0;; p++, x *= 2) 
        if (x > n) 
            break;
    x /= 2, p--;
    vector <pii> e;
    for (int i = p; i >= 0; i--) {
        if (n - x >= 0) {
            n -= x;
            e.pb({n, i});
        }
        x /= 2;
    }
    cout << p + 1 << " " << 2 * p + sz(e) - 1 << "\n";
    forn (i, 1, sz(e))
        cout << "1 " << p + 1 - e[i].sc << " " << e[i].fs << "\n";
    cout << "1 2 " << e[0].fs << "\n1 2 " << (1 << (p - 1)) + e[0].fs << "\n";
    forn (i, 1, p)
        cout << i + 1 << " " << i + 2 << " 0\n" << i + 1 << " " << i + 2 << " " << (1 << (p - i - 1)) << "\n";

    return 0;
}