#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repm(i, m, n) for (int i = m; i < (n); i++)
#define eps (1e-7)
#define inf (1e9)
#define pi (acos(-1))
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll a, b, c, m, n, ans;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int s;
    cin >> s;

    vi ss(1e6);

    ss[0] = s;
    rep(i, 1e6)
    {
        //奇数
        if (ss[i] % 2)
            ss[i + 1] = 3 * ss[i] + 1;
        else
            ss[i + 1] = ss[i] / 2;

        rep(j, i)
        {
            if (ss[j] == ss[i + 1])
            {
                cout << (i + 1) + 1 << endl;
                return 0;
            }
        }
    }

    return 0;
}