#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define deb(x) cout<< #x << " " << x << "\n";
#define MAX 9223372036854775807
#define MIN -9223372036854775807
#define PI 3.141592653589
#define setbits(n) __builtin_popcountll(n)
const ll mod=1e9+7;


int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T=clock();
    
    ll n,m;
    cin>>n>>m;
    vector<string> a(n);
    vector<vector<ll>> dp(n,vector<ll>(m,0));
    for(ll i=0;i<n;i++)
        cin>>a[i];
    dp[0][0]=1; 
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            if(i==0&&j==0) continue;
            ll sum=0;
            if(i>0&&a[i-1][j]=='.')
                sum=dp[i-1][j];
            if(j>0&&a[i][j-1]=='.')
                sum=(sum+dp[i][j-1])%mod;
            dp[i][j]=sum;
        }
    }
    cout<<dp[n-1][m-1];
    

    

    cerr<<"\n\nTIME: "<<(double)(clock()-T)/CLOCKS_PER_SEC<<" sec\n";
    T = clock();
    return 0;
}