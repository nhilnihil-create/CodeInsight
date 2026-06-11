#include<bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long int
#define fi first
#define se second
#define pub push_back
#define mkp make_pair
#define pi pair<int,int>
#define all(v) (v).begin(), (v).end()
#define rep(i, l, r) for(int i=(int)(l);i<(int)(r);i++)
#define repd(i, l, r) for (int i=(int)(l);i>=(int)(r);i--)
int power(int x, unsigned int y){int res = 1;while (y > 0){ if (y & 1){res = res*x;} y = y>>1;x = x*x;}return res;}
int powermod(int x, unsigned int y, int p){int res = 1;x = x % p;while (y > 0){if (y & 1){res = (res*x) % p;}y = y>>1; x = (x*x) % p;}return res;}
#define print2d(mat,n,m){for(int i=0;i<(int)(n);i++){for(int j=0;j<(m);j++){cout<<mat[i][j]<<" ";}cout<<endl;}}
#define print1d(mat,n){for(int i=0;i<(int)(n);i++)cout<<mat[i]<<" ";cout<<endl;}
#define clr(a,x) memset(a,x,sizeof(a))
#define rr(v) for(auto &val:v)
#define printpair(v) for(auto val: v){cout<<val.fi<<":"<<val.se<<", ";}cout<<endl;
#define print(v) for (const auto itr : v){cout<<itr<<' ';}cout<<endl;
#define init(v,x) for (auto &itr:v){itr=x;}
#define ln length()
const int mod = 998244353;
#define sz size()
const int inf = 1e18;
int n,arr[100005],k;
int dp[100005];
int f(int i){
    if(i==n-1){
        return 0;
    }
    int ans=inf;
    if(dp[i]!=-1){
        return dp[i];
    }
    rep(j,1,k+1) {
        if (i + j <= n - 1) {
            ans = min(ans, f(i + j) + abs(arr[i] - arr[i + j]));
        }
    }
    dp[i]=ans;
    return ans;
}
void solve() {
    clr(dp,-1);
    cin>>n>>k;
    rep(i,0,n){
        cin>>arr[i];
    }
    cout<<f(0)<<endl;
}

int32_t main(){
    fastIO
#ifndef ONLINE_JUDGE
    freopen(R"(C:\Users\swast\CLionProjects\untitled\input.txt)", "r", stdin);
#endif
    int t=1;
//    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}