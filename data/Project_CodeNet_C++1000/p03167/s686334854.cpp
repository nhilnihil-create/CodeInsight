#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mk make_pair
#define all(v) v.begin(),v.end()
#define fi first
#define se second
#define vl vector<long long int>
#define vvl vector<vector<ll> > 
#define fo(i,a,b) for(int i=a;i<b;i++)
#define rof(i,a,b)  for(int i=b;i>=a;i--)
using namespace std;
ll mod=1000000007;
int main()
{
    ll h,w;cin>>h>>w;
    char a[h+1][w+1];ll dp[h+1][w+1];
    memset(dp,0,sizeof(dp));
    fo(i,0,h)
        fo(j,0,w)
            cin>>a[i][j];
    dp[0][0]=1;
    fo(i,1,h)
    {
        if(a[i][0]=='.')
            dp[i][0] = a[i-1][0]=='.'?dp[i-1][0]:0;
        if(a[0][i]=='.')
            dp[0][i] = a[0][i-1]=='.'?dp[0][i-1]:0;
    }
    fo(i,1,h)
        fo(j,1,w)
        {
            dp[i][j] += a[i-1][j]=='.'?dp[i-1][j]:0;
            dp[i][j] += a[i][j-1]=='.'?dp[i][j-1]:0;
            dp[i][j]=dp[i][j]%(1000000007);
            if(a[i][j]=='#')
                dp[i][j]=0;
        }
    cout << dp[h-1][w-1];
}

