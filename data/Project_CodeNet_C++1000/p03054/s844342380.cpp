#include <bits/stdc++.h>
#define eps 1e-9
#define mod 1000000007
#define pi 3.14159265359
#define inf 1e18

using namespace std;

typedef long long ll;
typedef long double ld;

int dp[200005][4];
int w, h, n;
string s, t;

bool check(int i)
{
    if (dp[i][0]<=0)
        return false;
    if (dp[i][1]>=w+1)
        return false;
    if (dp[i][2]<=0)
        return false;
    if (dp[i][3]>=h+1)
        return false;
    return true;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int x, y;

    cin>>h>>w>>n;
    cin>>x>>y;
    cin>>s;
    cin>>t;
    s = "0" + s;
    t = "0" + t;
    dp[0][0] = y;
    dp[0][1] = y;
    dp[0][2] = x;
    dp[0][3] = x;

    for (int i=1; i<s.size(); i++)
    {
        dp[i][0] = dp[i-1][0];
        dp[i][1] = dp[i-1][1];
        dp[i][2] = dp[i-1][2];
        dp[i][3] = dp[i-1][3];

        // wants to move out of the board
        if (s[i] == 'L')
        {
            dp[i][0] = dp[i-1][0] - 1;
        }
        if (s[i] == 'R')
        {
            dp[i][1] = dp[i-1][1] + 1;
        }
        if (s[i] == 'U')
        {
            dp[i][2] = dp[i-1][2] - 1;
        }
        if (s[i] == 'D')
        {
            dp[i][3] = dp[i-1][3] + 1;
        }

        if (!check(i))
        {
            cout<<"NO";
            return 0;
        }

        // wants to prevent moving out the board
        if (t[i] == 'L')
        {
            dp[i][1] = max(1, dp[i][1] - 1);
        }
        if (t[i] == 'R')
        {
            dp[i][0] = min(dp[i][0] + 1, w);
        }
        if (t[i] == 'U')
        {
            dp[i][3] = max(1, dp[i][3] - 1);
        }
        if (t[i] == 'D')
        {
            dp[i][2] = min(dp[i][2] + 1, h);
        }

    }

    cout<<"YES";
    return 0;
}