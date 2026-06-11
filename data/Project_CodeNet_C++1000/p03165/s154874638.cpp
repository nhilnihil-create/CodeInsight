#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define inf 1000000000000000000
#define lli long long int
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s,t;
    cin>>s>>t;
    lli n=s.length(), m=t.length();
    lli dp[n+1][m+1];
    for(int i=0; i<=n; i++)
        dp[i][0]=0;
    for(int i=0; i<=m; i++)
        dp[0][i]=0;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(s[i-1]==t[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
        }
    }
    vector <char> v;
    int i=n,j=m;
    while(1)
    {
        if(i==0||j==0)
        break;
        if(dp[i][j]>max(dp[i-1][j],dp[i][j-1]))
            v.pb(s[i-1]), i--, j--;
        else if(dp[i][j]==dp[i-1][j])
            i--;
        else
            j--;
    }
    for(int i=v.size()-1; i>=0; i--)
        cout<<v[i];
    return 0;
}