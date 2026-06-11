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

int n, t, sum, mx;
int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> t;
        sum += t;
        mx = max(mx, t);
    }
    if (sum - mx > mx)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
