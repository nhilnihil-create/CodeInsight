#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n, m, X, Y;
    cin >> n >> m >> X >> Y;
    vector<int> x(n), y(m);
    rep(i, n) cin >> x[i];
    rep(i, m) cin >> y[i];
    for (int Z = X+1; Z <= Y; Z++)
    {
        bool ok = true;
        rep(i, n) if (x[i] >= Z) ok = false;
        rep(i, m) if (y[i] < Z) ok = false;
        if (ok)
        {
            cout << "No War" << endl;
            return 0;
        }
    }
    cout << "War" << endl;
    return 0;
}