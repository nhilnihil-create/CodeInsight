#include<bits/stdc++.h>
using namespace std;
#define ll  unsigned long long int
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mod 1000000007
#define wi while
#define vl vector<ll>
#define vi vector<int>
#define map map<char,ll>
#define endl "\n"
const int mxN = 200001;
const ll INF = 1e18L + 5;
ll dp[402][402];
//dp[i][j] contains the answer of range i to j
ll a[402];
ll sum(int l,int r)
{
    ll s = 0;
    for(int i=l;i<=r;++i)
    {
        s += a[i];
    }
    return s;
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    
    ll n;
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    for(int l=n;l>0;--l)
    {
        for(int r=l;r<=n;++r)
        {
            if(l==r)
            {
                dp[l][r] = 0;
            }
            else
            {
                dp[l][r] = INF;
                ll s = sum(l,r);
                for(int i=l;i<=r-1;++i)
                {
                    dp[l][r] = min(dp[l][r],dp[l][i]+dp[i+1][r]+s);
                }
            }
        }
    }
    cout<<dp[1][n]<<endl;



    
    return 0;

}
