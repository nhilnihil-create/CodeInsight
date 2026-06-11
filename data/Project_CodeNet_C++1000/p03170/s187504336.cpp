/*There's a possibility*/
/*but stop sucking first*/
#define dbg(...) ; 
#define db(...) ; 
#include "bits/stdc++.h"
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define f(i,a,b) for(i=a;i<b;i++)
#define fr(i,a,b) for(i=a;i>=b;i--)
#define endl '\n'
#define tst cout<<'*';
#define ll long long int
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define mod 1000000007
using namespace std;
 
int n,k,ar[105],dp[100005][2],mn;

int main()
{
    fast;
    int i,j;
    cin>>n>>k;
    f(i,0,n)
        cin>>ar[i];

    mn=*min_element(ar,ar+n);

    f(i,0,mn)
        dp[i][0]=1,dp[i][1]=0;

    f(i,mn,k+1)
    {
        dp[i][0]=1, dp[i][1]=0;
        f(j,0,n)
            if(i-ar[j]>=0)
            {
                dp[i][0]=min(dp[i][0],dp[i-ar[j]][1]);
                dp[i][1]=max(dp[i][1],dp[i-ar[j]][0]);
            }
    }

    (dp[k][1])?cout<<"First":cout<<"Second";
    // db(dp,0,k,0,2);
}