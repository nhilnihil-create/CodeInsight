#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int main()
{
    int n;
    cin >> n;
    vector<double> x(n);
    vector<string> u(n);
    rep(i, n) cin >> x[i] >> u[i];

    double res = 0;
    rep(i, n)
    {
        if (u[i] == "JPY")
        {
            res += x[i];
        }
        else
        {
            res += x[i] * 380000.0;
        }
    }
    cout << res << '\n';
    return 0;
}
