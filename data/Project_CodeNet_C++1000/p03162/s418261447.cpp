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

const int N=1e5+1;
ll dp[N][3],n;
vector<vector<ll>> a(N,vector<ll>(3));


int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T=clock();
    
    cin>>n;
    for(ll i=0;i<n;i++)
        cin>>a[i][0]>>a[i][1]>>a[i][2];
    memset(dp,-1,sizeof(dp));
    dp[0][0]=dp[0][1]=dp[0][2]=0;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<3;j++){
            for(ll k=0;k<3;k++){
                if(k==j) continue;
                dp[i+1][j]=max(dp[i][k]+a[i][k],dp[i+1][j]);
            }
        }
    }
    cout<<max(dp[n][0],max(dp[n][1],dp[n][2]));


    cerr<<"\n\nTIME: "<<(double)(clock()-T)/CLOCKS_PER_SEC<<" sec\n";
    T = clock();
    return 0;
}