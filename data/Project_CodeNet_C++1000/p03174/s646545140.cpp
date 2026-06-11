#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const int mod=1000000007;
    int n;
    cin >> n;
    vector<int> c((1<<n),0);
    for(int i=0;i<(1<<n);i++) c[i]=__builtin_popcount(i);
    vector<vector<int>> v(n,vector<int>(n,0));
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin >> v[i][j];
    vector<int> dp((1<<n),0);
    dp[0]=1;
    for(int i=0;i<n;i++)
    {
        for(int m=0;m<(1<<n);m++)
        {
            if(c[m]!=i) continue;
            for(int j=0;j<n;j++) if(v[i][j]==1&&(m&(1<<j))==0) dp[m^(1<<j)]=(dp[m^(1<<j)]+dp[m])%mod;
        }
    }
    cout << dp[(1<<n)-1] << "\n";
    return 0;
}
