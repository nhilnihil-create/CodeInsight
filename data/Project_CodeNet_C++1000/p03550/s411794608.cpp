//ヘッダー
#include<bits/stdc++.h>
using namespace std;

//型定義
typedef long long ll;

//定数
const ll INF=1e+18;
const int MOD=1e+9+7;

//REPマクロ
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define REP2(i,a,b) for(ll i=a;i<(ll)(b);i++)
#define REPD2(i,a,b) for(ll i=a;i>(ll)(b);i--)

// 多次元 vector 生成
template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
  return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

//vectorの扱い
#define ALL(x) (x).begin(),(x).end() //sortなどの引数省略
#define SIZE(x) ((ll)(x).size()) //size
#define MAX(x) *max_element(ALL(x)) //最大値
#define MIN(x) *min_element(ALL(x)) //最小値

int main(){
    int N;
    ll Z,W;
    cin>>N>>Z>>W;
    vector<ll> a(N);
    REP(i,N) cin>>a[i];

    vector<vector<ll>> dp(N+1,vector<ll>(2));
    REP(i,N+1){
        dp[i][0]=-INF;
        dp[i][1]=INF;
    }

    ll X,Y;
    REPD(i,N){
        //Xについて
        if(i==0){Y=W;}
        else{Y=a[i-1];}
        dp[i][0]=max(dp[i][0],abs(Y-a[N-1]));
        REP2(j,i+1,N){
            dp[i][0]=max(dp[i][0],dp[j][1]);
        }
        //Yについて
        if(i==0) continue;
        X=a[i-1];
        dp[i][1]=min(dp[i][1],abs(X-a[N-1]));
        REP2(j,i+1,N){
            dp[i][1]=min(dp[i][1],dp[j][0]);
        }
    }
    cout<<dp[0][0]<<endl;

}