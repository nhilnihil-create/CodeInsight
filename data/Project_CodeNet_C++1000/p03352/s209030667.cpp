#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rem(i, m, n) for (int i = m; i < (n); i++)
#define eps (1e-7)
#define inf (1e9)
#define pi (acos(-1))
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int x;
    cin >> x;
    vi a;
    a.push_back(1);
    rem(i, 2, 32)
    {
        int p = 2;
        //cout << "\n";
        //cout << "i : " << i << "\n";
        while (1)
        {
            int x = pow(i, p);

            //cout << "x : " << x << "\n";
            if (x <= 1000)
            {
                a.push_back(x);
                p++;
            }
            else
                break;
        }
    }

    int ans = -1;
    for (const auto &e : a)
    {
        //cout << "e : " << e << "\n";

        if (e <= x)
        {
            ans = max(e, ans);
            //cout << "ans : " << ans << "\n";
        }
    }

    cout << ans << "\n";

    return 0;
}