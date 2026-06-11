/*There's a possibility*/
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

ll dp[100][100005];

int main()
{
    fast;
    int n,k,i,j;
    cin>>n>>k;
    int ar[n];
    f(i,0,n)
        cin>>ar[i],dp[i][0]=1;
    f(j,0,ar[0]+1)
        dp[0][j]=1;

    f(i,1,n)
        f(j,1,k+1)
        {
            dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
            if(j>ar[i])
                dp[i][j]=(dp[i][j]-dp[i-1][j-ar[i]-1]+mod)%mod;
        }

    cout<<dp[n-1][k];
    //db(dp,0,n-1,0,k);
}