#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

const int INF = 100100100;

int main()
{
    int n, l;
    cin >> n >> l;

    vector<int> c(n), t(n);
    rep (i, n)
        cin >> c[i] >> t[i];

    int ans = INF;
    rep (i, n)
        if (t[i] <= l)
            ans = min(c[i], ans);

    if (ans == INF)
        cout << "TLE" << endl;
    else
        cout << ans << endl;
    return 0;
}