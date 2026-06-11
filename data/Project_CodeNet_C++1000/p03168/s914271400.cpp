#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cout<<fixed<<setprecision(50);
    int n;cin>>n;
    ld a[n+5];
    for(int i=1;i<=n;i++)    cin>>a[i];

    ld dp[n+5][n+5];
    memset(dp,0,sizeof(dp));

    dp[1][1]=a[1];
    dp[1][0]=1-a[1];

    for(int i=2;i<=n;i++){
        for(int heads=0;heads<=i;heads++){
            dp[i][heads]=((heads)?(a[i]*dp[i-1][heads-1]):0)+(1-a[i])*dp[i-1][heads];
            // cout<<i<<" "<<heads<<" "<<dp[i][heads]<<"\n";
        }
    }

    ld ans=0.0;
    for(int i=1;i<=n;i++){
        if(2*i>n)   ans+=dp[n][i];
    }
    
    cout<<ans<<"\n";
}