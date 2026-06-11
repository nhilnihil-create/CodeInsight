#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;
#define DEBUG freopen("in.txt", "r", stdin);

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

ll n, m;

int main() {
    cin >> n >> m;
    if (n < m)
        swap(n, m);
    if (m == 1) {
        if (n == 1)
            cout << 1 << endl;
        else
            cout << n - 2 << endl;
    } else {
        cout << (n - 2) * (m - 2) << endl;
    }

    return 0;
}
