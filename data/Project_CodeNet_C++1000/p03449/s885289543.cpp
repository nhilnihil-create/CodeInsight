#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> candy(2, vector<int>(n));
    rep(i, 2)
    {
        rep(j, n)
        {
            cin >> candy[i][j];
        }
    }
    int ans = 0;
    rep(i, n)
    {
        int x = 0;
        int sum = 0;
        rep(y, n)
        {
            sum += candy[x][y];
            if (i == y)
            {
                x++;
                sum += candy[x][y];
            }
        }
        ans = max(ans, sum);
    }
    cout << ans << endl;
    return 0;
}