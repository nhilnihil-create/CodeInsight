#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()
#define all2(a, b) (a).begin(), (a).begin() + (b)
#define debug(vari) cerr << #vari << " = " << (vari) << endl;

int main()
{
    int n;
    cin >> n;
    vector<int> t(n), x(n), y(n);
    rep(i, n) cin >> t[i] >> x[i] >> y[i];

    rep(i, n)
    {
        int dt, dl;
        if (i == 0)
        {
            dt = t[i];
            dl = x[i] + y[i];
        }
        else
        {
            dt = t[i] - t[i - 1];
            dl = abs(x[i] - x[i - 1]) + abs(y[i] - y[i - 1]);
        }

        if (dt < dl || (dt % 2 != dl % 2))
        {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

    return 0;
}
