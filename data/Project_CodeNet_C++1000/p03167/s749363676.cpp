//https://atcoder.jp/contests/dp/tasks/dp_h

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
    int n,m;
    cin >> n >> m;
    string s[n];
    for(int i=0 ; i<n; i++)
        cin >> s[i];
    ll M = 1e9+7;
    ll dp[n][m];
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<m ; j++)
        {
            if(s[i][j] == '#')
            {
                dp[i][j] = 0;
                continue;
            }
            if(i==0 && j==0)
                dp[i][j] = 1;
            else if(i==0)
                dp[i][j] = dp[i][j-1];
            else if(j==0)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = (dp[i-1][j] + dp[i][j-1])%M;
        }
    }
    /*for(int i=0 ; i<n ; i++)
    {
      for(int j=0 ; j<m ; j++)
            cout << dp[i][j] << " ";
      cout << "\n";
    }*/
    cout << dp[n-1][m-1];
    return 0;
}
