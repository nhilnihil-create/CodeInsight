#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define F               first
#define S               second
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18 + 1
#define endl            '\n'
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define forI(i,a,n)     for(int i=a;i<=n;i++)
#define forD(i,a,n)     for(int i=n;i>=a;i--)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
 
void init(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

int a[100][100];
int dp[22][(1<<22)];

int compute(int i, int ws, int n){
    if(i == n+1)    return (ws == 0) ? 1 : 0;
    
    if(dp[i][ws] != -1) return dp[i][ws];
    
    int ans=0;
    forI(w, 0, n-1){
        if((ws&(1<<w)) && a[i][w+1]){
            ans = (ans%mod + compute(i+1, ws^(1<<w), n)%mod)%mod;
        }
    }

    return dp[i][ws] = ans;
}

void solve(){
    int n;  cin>>n;
    forI(i, 1, n)   forI(j, 1, n)   cin>>a[i][j];
    memset(dp, -1, sizeof dp);
    cout<<compute(1, (1<<n)-1, n);
}   

int32_t main(){
    init();
    // w(t) 
    solve();
    return 0;
}