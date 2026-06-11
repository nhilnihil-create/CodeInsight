#include <bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int 	     	  long long   // [9,223,372,036,854,775,807 to -9.....808] 19 digits
#define pb                push_back 
#define all(x)            (x).begin(),(x).end()
#define mp                make_pair
#define vi                vector<int> 
#define vpi               vector<pair<int,int>>
#define mii               map<int,int>
#define x                 first
#define y                 second 
#define mem(a,x)          memset(a,x,sizeof(a))
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define sz(x)             (int)((x).size())

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; // find_by_order()  // order_of_key

//const int32_t hellhsh = 444440583533; const double pi=2*acos(0.0); 
const int32_t mod = 1e9+7;
const int32_t maxn=4e2+5;
int inf=1e18;

int n,a[maxn],dp[maxn][maxn],pre[maxn];

void solve(){
    cin>>n;
    rep(i,0,n) cin>>a[i];
    rep(i,0,n){
        rep(j,0,n){
            dp[i][j]=inf;
        }
    }
    rep(i,0,n) pre[i+1]=pre[i]+a[i],dp[i][i]=a[i];
    

    for(int l=n-1;l>=0;l--){
        rep(r,l,n){
            rep(i,l,r){
                dp[l][r]=min(dp[l][r],dp[l][i]+dp[i+1][r]+pre[r+1]-pre[l]);
            }
            //cout<<l<<' '<<r<<' '<<dp[l][r]<<'\n';
        }
    }
    cout<<dp[0][n-1]-pre[n];
}

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tc=1,k=1;                                                                                                                  
    //cin>>tc;
    while(tc--){
        //cout<<"Case #"<<k++<<": ";
        solve();
    }
    return 0;
}