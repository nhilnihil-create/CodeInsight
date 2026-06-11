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
 
double ar[3000], dp[3000][3000],ans;
int n;

int main()
{
    fast;
    int i,j;
    cin>>n;
    f(i,0,n)
        cin>>ar[i];
    
    dp[n-1][0]=1-ar[n-1];
    dp[n-1][1]=ar[n-1];

    fr(i,n-2,0)
    {
        dp[i][0]=(1-ar[i])*dp[i+1][0];
        f(j,1,n+1)
            dp[i][j]=ar[i]*dp[i+1][j-1]+(1-ar[i])*dp[i+1][j];
    }

    f(i,(n+1)/2,n+1)
        ans+=dp[0][i];
    cout<<std::setprecision(9) <<ans;
    db(dp,0,2,0,3);
}