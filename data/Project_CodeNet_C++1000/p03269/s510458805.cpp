#include <bits/stdc++.h>

#define mp make_pair
#define mt make_tuple
#define pb push_back
#define ff first
#define ss second
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define forrn(i, a, b) for (int i = (a); i < (int)(b); i++)
#define PYMOD(A, M) ((((A) % (M)) + (M)) % (M))
using ll = long long;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int l;
    cin >> l;

    int n = 0;
    for (int i = 31; i >= 0; i--) {
        if ((l >> i) & 1) {
            n = i + 1;
            break;
        }
    }

    vector<int> u, v, w;

    for (int i = 1; i < n; i++) {
        {
            u.pb(i);
            v.pb(i + 1);
            w.pb(1 << (n - i - 1));
        }
        {
            u.pb(i);
            v.pb(i + 1);
            w.pb(0);
        }
    }

    for (int i = 0; i < n - 1; i++) {
        if ((l >> i) & 1) {
            u.pb(1);
            v.pb(n - i);
            w.pb(l & ~((1 << (i + 1)) - 1));
        }
    }

    cout << n << " " << u.size() << endl;
    forn(i, u.size())
        cout << u[i] << " " << v[i] << " " << w[i] << endl;

    return 0;
}
