#include<bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define debug(v) cout<<#v<<":";for(auto x:v){cout<<x<<' ';}cout<<endl; 
#define INF 1000000000
#define mod 1000000007
typedef long long ll;
const ll LINF = 1001002003004005006ll;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

//DP解法
signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    ll n,X,Y;cin>>n>>X>>Y;
    vector<ll> a(n+1);
    rep(i,n) cin>>a[i+1];
    //dp[i][先手後手]=山札からi枚とったときの一番いい値
    //0を先手1を後手にする
    //0->最大値を更新，1->最小値を更新
    vector<vector<ll>> dp(n+1,vector<ll>(2));

    for(int i=n-1;i>=0;i--){
        ll y=(i==0?Y:a[i]);
        //yをi番目のカードにして残り全部とってゲームを終える
        dp[i][0]=abs(y-a[n]);
        //後手の未来のあらゆる最適から一番デカイのを選ぶ．
        for(int j=i+1;j<n;j++) chmax(dp[i][0],dp[j][1]);


        ll x=(i==0?X:a[i]);
        dp[i][1]=abs(x-a[n]);
        for(int j=i+1;j<n;j++) chmin(dp[i][1],dp[j][0]);
    }
    

    //dp[0][0]がゲーム開始時から未来を見たときの一番イイ値
    cout<<dp[0][0]<<endl;
    return 0;
}
