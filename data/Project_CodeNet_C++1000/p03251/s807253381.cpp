#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main()
{
    int n, m, X, Y;
    cin >> n >> m >> X >> Y;
    vector<int> x(n), y(m);
    rep (i, n)
        cin >> x[i];
    rep (i, m)
        cin >> y[i];
    sort(x.rbegin(), x.rend());
    sort(y.begin(), y.end());

    bool ok = false;
    for (int i = X + 1; i <= Y; i++)
        if (x[0] < i && y[0] >= i)
            ok = true;

    cout << (ok ? "No War" : "War") << endl;
    return 0;
}