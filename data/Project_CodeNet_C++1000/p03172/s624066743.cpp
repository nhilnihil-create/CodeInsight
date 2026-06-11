#include <bits/stdc++.h>
using namespace std;
    
#define IOS cin.sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define rep(i, n) for (int i = 0; i < n; i++)
#define repn(i, a, b) for (int i = a;i<=b;i++)
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define mem(x) memset(x, 0, sizeof(x))
#define ritr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define pai pair < int, int> 
#define pal pair < ll, ll> 
#define vi vector <int> 
#define vl vector < ll > 
#define vpai vector < pii > 

const int mod = 1e9+7;
const int INF = INT_MAX;
const int sze = 3005;

void solve() {
    int n,k;
    cin>>n>>k;
    ll arr[n];
    rep(i,n) cin>>arr[i];

    int dp[n+1][k+6];
    // mem(dp);

    rep(i,n+1) dp[i][0]=1;
    rep(i,k+1) dp[0][i]=0;
    dp[0][0]=1;

    for(int i=1;i<=n;i++){
        vl pre(k+1);
        pre[0]=dp[i-1][0];
        repn(j,1,k) pre[j]=(pre[j-1]+dp[i-1][j])%mod;

        for(int j=1;j<=k;j++){
            if(arr[i-1]>=j){
                dp[i][j]=pre[j]%mod;
                
            }else dp[i][j]=(pre[j]-pre[j-arr[i-1]-1]+mod)%mod;
        }
    }

    // rep(i,n+1){
    //     rep(j,k+1) cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // }
    cout<<dp[n][k]<<endl;
}

int main() {
    IOS;

    int t = 1;
    //cin >> t;
    while (t--) {
       solve();
    }

  return 0;
}