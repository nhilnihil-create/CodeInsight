#include<bits/stdc++.h>
#define ll long long
#define inf 9999999999999999
#define F first
#define S second
#define eb emplace_back
#define mpp make_pair
#define P(x) cout<<__LINE__ <<": "<<#x<<' '<<(x)<<'\n'
#define dbg cout<<__LINE__ <<": 0manush\n"
#define read(x) freopen("input.txt","r",stdin)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pi 2*acos(0.0)
#define ee exp(1)
#define mx 100009
#define mod 10000007
using namespace std;
int main(){//read(x);
//fast;
ll r,g,h,i,j,x,y,t,e,a,b,c,d,n,l,k;

    cin>>n;
    ll m[n+5][3],dp[n+55][3];
    for(i=0;i<n;i++)
        for(j=0;j<3;j++)
            cin>>m[i][j];

    dp[n][0]=dp[n][1]=dp[n][2]=0;
    l=0;
    for(i=n-1;i>=0;i--){
        dp[i][0]=max(m[i][1]+dp[i+1][1],m[i][2]+dp[i+1][2]);
        dp[i][1]=max(m[i][0]+dp[i+1][0],m[i][2]+dp[i+1][2]);
        dp[i][2]=max(m[i][1]+dp[i+1][1],m[i][0]+dp[i+1][0]);
    }
    //cout<<dp[0][0]<<' '<<dp[0][1]<<' '<<dp[0][2]<<endl;
    l=max(dp[0][0],max(dp[0][1],dp[0][2]));
    cout<<l<<endl;
}



















