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
    ll n,k;cin>>n>>k;
    ll a[n],dp[k+1];
    memset(dp,0,sizeof(dp));
    fo(i,0,n)
        cin>>a[i];
    fo(i,1,k+1)
    {
        dp[i]=0;
        fo(j,0,n)
        {
            if(a[j]<=i&&dp[i-a[j]]==0)
                dp[i]=1;
        }
    }
    if(dp[k])
        cout << "First";
    else    cout << "Second";
}

