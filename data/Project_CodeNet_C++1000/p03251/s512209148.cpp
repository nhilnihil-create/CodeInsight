#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define put(i) cout << fixed << i << endl
using namespace std;
using ll = long long;

int main() {
    int n, m, X, Y;
    cin >> n >> m >> X >> Y;
    vector<int> x(n), y(m), z;
    rep(i, n) cin >> x[i];
    rep(i, m) cin >> y[i];

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    for (int i = X + 1; i <= Y; i++) {
        z.push_back(i);
    }

    for (int i = 0; i < z.size(); i++) {
        if (x[n - 1] < z[i] && y[0] >= z[i]){
            put("No War");
            return 0;
        }
    }
    put("War");
}