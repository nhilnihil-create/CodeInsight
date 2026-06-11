#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
//cout << setprecision(20) << 

int main() {
    ll n, m, X, Y; cin >> n >> m >> X >> Y;
    vector<int> x(n); for (int i = 0; i < n; ++i) cin >> x[i];
    vector<int> y(m); for (int i = 0; i < m; ++i) cin >> y[i];
    bool ok = false;
    for (int i = X + 1; i <= Y; ++i) {
        bool check = true;
        for (int j = 0; j < n; ++j) {
            if (i <= x[j]) {
                check = false;
                break;
            }
        }
        for (int j = 0; j < m; ++j) {
            if (i > y[j]) {
                check = false;
                break;
            }
        }
        if (check) {
            ok = true;
            break;
        }
    }
    if (ok) cout << "No War" << endl;
    else cout << "War" << endl;
}