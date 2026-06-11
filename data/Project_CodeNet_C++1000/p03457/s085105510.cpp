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

    bool ok = true;
    int time = 0, dx = 0, dy = 0;
    rep(i, n)
    {
        time = t[i] - time;
        dx = abs(x[i] - dx);
        dy = abs(y[i] - dy);

        if (time % 2 != (dx + dy) % 2 || dx + dy > time)
        {
            ok = false;
        }
    }

    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}
