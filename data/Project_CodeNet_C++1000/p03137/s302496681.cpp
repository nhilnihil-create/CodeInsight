#include <bits/stdc++.h>
using namespace std;
#define BE(x) (x).begin(), (x).end()

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> x(m);
    for (int i = 0; i < m; i++) cin >> x[i];

    if (n >= m) {
        cout << 0 << endl;
        return 0;
    }
    else {
        sort (BE(x));
        vector<tuple<int,int,int>> y(m-1);
        for (int i = 1; i < m; i++)
            y[i-1] = make_tuple(x[i]-x[i-1], x[i-1], x[i]);
        sort (BE(y));
        int s = m-1;
        vector<int> z1(n), z2(n);
        z1[0] = x.front(), z2[0] = x.back();
        for (int i = 1; i < n; i++) {
            z1[i] = get<2>(y[s-i]);
            z2[i] = get<1>(y[s-i]);
        }
        sort (BE(z1)), sort (BE(z2));
        int ans = 0;
        for (int i = 0; i < n; i++)
            ans += z2[i] - z1[i];
        cout << ans << endl;
    }
}