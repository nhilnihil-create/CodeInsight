#include <bits/stdc++.h>
#define INF 1e18
#define int long long
#define Rep(i, a, n) for (int i = (a); i < (n); i++)
#define rep(i, n) Rep(i, 0, n)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef pair<int, int> P;
typedef pair<int, P> PP;
const int mod = 1000000007;
//const int mod = 998244353;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b, k;
    cin >> a >> b >> k;
    rep(i, k)
    {
        if (i % 2 == 0)
        {
            b += (a / 2);
            a /= 2;
        }
        else
        {
            a += (b / 2);
            b /= 2;
        }
    }
    cout << a << " " << b << endl;
}
