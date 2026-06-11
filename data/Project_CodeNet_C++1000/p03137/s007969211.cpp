#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, m; cin >> n >> m;
    vector<int> x(m);
    rep(i, m) cin >> x[i];

    sort(x.begin(), x.end());
    vector<int> y(m-1);
    rep(i, m-1) y[i]=x[i+1]-x[i];
    sort(y.rbegin(), y.rend());
    int ans = 0;
    for (int i = n-1; i < m-1; i++) {
        ans += y[i];
    }
    cout << ans << endl;
}