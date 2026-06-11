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
#define mod 1000000007
using namespace std;
ll dp[404][404];ll a[404],pre[404];
ll cnt(ll i,ll j)
{
    if(i>=j)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    ll mini = 1000000000000009;
    for(ll k=i;k<j;k++)
    {
        if(i>0)
            mini = min(mini,cnt(i,k)+cnt(k+1,j)+pre[j]-pre[i-1]);
        else
            mini = min(mini,cnt(i,k)+cnt(k+1,j)+pre[j]);
    }
    return dp[i][j] = mini;
}
int main()
{
    ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    ll n;cin>>n;
    memset(dp,-1,sizeof(dp));
    fo(i,0,n)
        cin>>a[i];
    pre[0]=a[0];
    fo(i,1,n)
        pre[i]=pre[i-1]+a[i];
    cout << cnt(0,n-1);
}

