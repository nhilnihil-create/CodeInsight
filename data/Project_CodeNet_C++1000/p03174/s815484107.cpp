#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
const ll mod = 1e9+7;

ll dp[2097155];

main(){
    int n;cin>>n;
    int a[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cin>>a[i][j];
    }
    for(int i=1;i<(1<<n);i++) dp[i]=0;
    dp[0]=1;
    for(int mask=0;mask<(1<<n);mask++){
        int x = __builtin_popcount(mask);
        for(int j=0;j<n;j++){
            if(!(mask&(1<<j)) && a[x][j]) dp[mask^(1<<j)]+= dp[mask],dp[mask^(1<<j)]%=mod; 
        }
    }
    cout<<dp[(1<<n)-1];
}