#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;

int main() {
    int n, m;
    cin >> n >> m;

    if (n >= m) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> x(m);
    rep(i,m) cin >> x[i];
    sort(x.begin(), x.end());

    int ans = 0;
    vector<int> d(m-1);

    rep(i,m-1) {
        d[i] = x[i+1] - x[i];
    }

    sort(d.begin(), d.end());

    for (int i=m-2; i>=m-n; i--) ans += d[i];

    cout << x[m-1] - x[0] -ans << endl;
    return 0;
}