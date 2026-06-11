#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

ll r, d, x;
int main() {
    cin >> r >> d >> x;
    for (int i = 0; i < 10; ++i) {
        x = r * x - d;
        cout << x << endl;
    }
    return 0;
}
