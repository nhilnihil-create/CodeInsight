#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define rep(i, s, e) for (int i = s; i < e; i++)
#define endl '\n'
int main()
{
    int n;
    lli y;
    cin >> n >> y;
    rep(i, 0, n+1)
    {
        rep(j, 0, n+1)
        {
            int k = n - i - j;
            if (k < 0)
                continue;
            if (10000 * i + 5000 * j + 1000 * k == y)
            {
                int ans[3] = {i, j, k};
                cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
                return 0;
            }
        }
    }
    cout << "-1 -1 -1" << endl;
}