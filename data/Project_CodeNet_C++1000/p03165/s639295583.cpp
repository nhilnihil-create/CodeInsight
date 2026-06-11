// https://atcoder.jp/contests/dp/tasks/dp_f
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
typedef vector<ll> vi;
typedef vector<vi> vii;
typedef vector<string> vs;
typedef vector<vs> vss;
#define rep(i, k, n) for (int i = k; i < (int)(n); i++)

int main()
{
    string a, b;
    cin >> a >> b;
    vii dp(a.length() + 1, vi(b.length() + 1));

    rep(i, 0, a.length() + 1)
    {
        rep(j, 0, b.length() + 1)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (a[i - 1] == b[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    string ans;
    int i = a.length();
    int j = b.length();
    while (i != 0 && j != 0)
    {
        if (dp[i][j] == dp[i - 1][j])
            i--;
        else if (dp[i][j] == dp[i][j - 1])
            j--;
        else
        {
            //when a[i - 1] == b[j-1]
            ans = a[i - 1] + ans;
            i--;
            j--;
        }
    }

    cout << ans << endl;
}