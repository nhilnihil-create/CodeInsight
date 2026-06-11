#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define rt return 0
#define endln "\n"
#define all(v) v.begin(), v.end()
#define for1(i, a, b) for (long long int i = a; i < b; i++)
#define for2(i, a, b) for (long long int i = a; i > b; i--)
//  cout << fixed << setprecision(0) << pi <<" "<<npi<<endl;typedef long long int i;
typedef long long int lli;
typedef pair<lli, lli> pll;
lli n;
double dp[301][301][301];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // lli n;
    cin >> n;
    // double dp[301][301][301];
    lli c1 = 0, c2 = 0, c3 = 0;
    for1(i, 0, n)
    {
        lli k;
        cin >> k;
        if (k == 1)
        {
            c1 += 1;
        }
        else if (k == 2)
        {
            c2 += 1;
        }
        else if (k == 3)
        {
            c3 += 1;
        }
    }
    dp[0][0][0] = 0.00;
    for1(k, 0, n + 1)
    {
        for1(j, 0, n + 1)
        {
            for1(i, 0, n + 1)
            {
                double s = i + j + k;
                if (s == 0 || s > n)
                {
                    continue;
                }
                else
                {
                    dp[i][j][k] = 1;
                    if (i)
                    {
                        dp[i][j][k] += (double)((double)i / (double)n * dp[i - 1][j][k]);
                    }
                    if (j)
                    {
                        dp[i][j][k] += (double)((double)j / (double)n * dp[i + 1][j - 1][k]);
                    }
                    if (k)
                    {
                        dp[i][j][k] += (double)((double)k / (double)n * dp[i][j + 1][k - 1]);
                    }
                }
                dp[i][j][k] *= (double)(n / (double)s);
                // cout << i << " " << j << " " << k << " " << dp[i][j][k] << endl;
            }
        }
    }
    cout << fixed << setprecision(15) << dp[c1][c2][c3] << endl;
}