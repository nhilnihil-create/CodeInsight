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
#define S second　//pairの二つ目の要素

ll n;
vector<vector<long long>> v;
long long sum[70000] = {0};
long long dp[70000] = {0};

//sum[]に全ての集合毎の点数をセット
void sumset() {
    rep(i,1<<n){
        sum[i]=0;
        rep(j,n){
            for(int k = j + 1; k < n; ++k){
                if(((i >> j) & 1) && ((i >> k) & 1)) sum[i]+=v[j][k];
            }
        }
    }
}

long long solve(int now){
    if(dp[now] != -1) return dp[now];
    //  dp[S]=max(dp[S∖T]+sum[T]) TはSの部分集合
    long long ans = 0;
    // S⊃TなるTを全部列挙
//    for(int x = now; x > 0; --x) {
//        x &= now;
    for(int x = now; x > 0; --x &= now) {
        ans=max(ans, solve(now-x)+sum[x]);
    }
    return dp[now] = ans;
}

int main(){
    // 入力
    cin >> n;
    v.resize(n);
    for(int i = 0; i < n; ++i) {
    v[i].resize(n);
    for(int j = 0; j < n; ++j) cin >> v[i][j];
    }
    sumset();
// dp[]全てに-1を代入
    rep(i,1<<n) dp[i]=-1;
// dp[]の１要素のものに0を代入
    rep(i,n) dp[1<<i]=0;
    cout << solve((1 << n) - 1) << endl;
    return 0;
}