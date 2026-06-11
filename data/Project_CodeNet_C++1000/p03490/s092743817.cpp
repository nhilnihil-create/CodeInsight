#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll INF = 1e10;
int main()
{
    int x, y;
    string s;
    cin >> s >> x >> y;
    int n = s.size();

    vector<vector<bool>> dp(16010, vector<bool>(8010));
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            dp[i][j] = false;
        }
    }
    dp[0][1] = true;

    vector<int> vx;
    vector<int> vy;
    int pos = 0;
    int dr = 1;
    while(pos < n)
    {
        int count = 0;
        while(pos < n && s[pos] == 'F')
        {
            pos++;
            count++;
        }
        if(dr == 1) vx.push_back(count);
        else vy.push_back(count);

        if(pos >= n) break;

        int tc = 0;
        while(pos < n && s[pos] == 'T')
        {
            pos++;
            tc++;
        }
        if(tc % 2 == 1) dr *= -1;
    }

    for(int i = 1; i < vx.size(); i++)
    {
        for(int j = 0; j <= n; j++)
        {
            if(j+vx[i] <= n) dp[j+vx[i]][i+1] = dp[j+vx[i]][i+1] || dp[j][i];
            if(vx[i] <= j) dp[j-vx[i]][i+1] = dp[j-vx[i]][i+1] || dp[j][i];
        }
    }

    if(!dp[abs(vx[0]-x)][vx.size()])
    {
        cout << "No" << endl;
        return 0;
    }

    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            dp[i][j] = false;
        }
    }
    dp[0][0] = true;
    for(int i = 0; i < vy.size(); i++)
    {
        for(int j = 0; j <= n; j++)
        {
            if(j+vy[i] <= n) dp[j+vy[i]][i+1] = dp[j+vy[i]][i+1] || dp[j][i];
            if(vy[i] <= j) dp[j-vy[i]][i+1] = dp[j-vy[i]][i+1] || dp[j][i];
        }
    }
    if(!dp[abs(y)][vy.size()])
    {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
}