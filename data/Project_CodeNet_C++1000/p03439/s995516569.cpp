#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ff first
#define ss second
#define quick                    \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define time cerr << (0.1 * clock()) / CLOCKS_PER_SEC << endl;
#define mod 1000000007
typedef long long ll;
typedef pair<ll, ll> pl;
#define forn(n) for (ll i = 0; i < ll(n); i++)

int query(int i) {
    cout << i << endl;
    fflush(stdout);
    string s;
    cin >> s;
    if (s == "Vacant") {
        return -1;
    }
    if (s == "Female") {
        return 1;
    }
    return 0;
}

void solve() {
    int n;
    cin >> n;
    int ini = query(0);
    if (ini == -1) {
        return;
    }
    int l = 0, r = n;
    while (l < r) {
        int mid = l + ((r - l) / 2);
        auto res = query(mid);
        if (res == -1) {
            return;
        }
        int exp = ((mid) % 2 + ini) % 2;
        if (exp == res) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return;
}

int main() {
    quick;
    solve();
    // ll t;
    // cin >> t;
    // while (t--) {
    //     solve();
    // }
}