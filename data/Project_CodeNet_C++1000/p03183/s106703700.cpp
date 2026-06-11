#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)

typedef long long ll;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
//定数
#define INF 1000000000 //10^9:極めて大きい値,∞
//略記
#define PB push_back //vectorヘの挿入
#define MP make_pair //pairのコンストラクタ
#define F first //pairの一つ目の要素
#define S second //pairの二つ目の要素


int main(){
    int n;
    cin>>n;
    vector<int> w(n), s(n), v(n), box(n);
    rep(i,n) cin>>w[i]>>s[i]>>v[i];
    rep(i,n) box[i]=i;
    sort(box.begin(),box.end(),[&](int x,int y){return w[x]+s[x]<w[y]+s[y];});
    vector<vector<ll>> dp(n+1, vector<ll>(20005));
    dp[0][0]=0;
    rep(i,n){
        int ind=box[i];
        rep(j,20005){
            dp[i+1][j]=dp[i][j];
            if(j-w[ind]<=s[ind] && j-w[ind]>=0){ 
                dp[i+1][j]=max(dp[i+1][j],dp[i][j-w[ind]]+v[ind]);
                }
        }
    }
    ll ans=0;
    rep(j,20005) ans=max(ans,dp[n][j]);
    cout<<ans<<endl;
    return 0;
}