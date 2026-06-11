#include<bits/stdc++.h>

#define inp 200005
#define check exit(0)
#define nl cout<<endl;
#define mod 1000000007 
#define ll long long int
#define trace(x) cerr<<#x<<" : "<<x<<endl;
#define jaldi ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define deb(v) for(int i=0;i<v.size();i++) {cout<<v[i]; (i==v.size()-1) ? cout<<"\n":cout<<" "; }

using namespace std;

// ... :)

int main()
{
    jaldi
    
    int n;
    cin>>n;

    int arr[n][n];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++) cin>>arr[i][j];
    }    

    vector<ll> dp(1<<n,0);
    dp[0]=1;

    for(int mask=0;mask<(1<<n);mask++)
    {
        //trace(mask);
        int taken = __builtin_popcount(mask);
        for(int b=0;b<n;b++)
        {
            if(!arr[taken][b] || (mask & (1<<b))) continue;
            dp[mask|(1<<b)]+=dp[mask];
            dp[mask|(1<<b)]%=mod;
        }
        //deb(dp);
    }
    cout << dp[(1<<n)-1];

    return 0;
}