//ヘッダー
#include<bits/stdc++.h>
using namespace std;

//型定義
typedef long long ll;

//定数
const int INF=1e+9;
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
    string S;
    cin>>S;
    int N=S.size();
    vector<vector<ll>> dp(N+1,vector<ll>(4,0));
    dp[0][0]=1;
    REP(i,N){
        if(S[i]=='?'){
            REP(j,4){
                dp[i+1][j]=3*dp[i][j]%MOD;
            }
        }else{
            REP(j,4){
                dp[i+1][j]=dp[i][j]%MOD;
            }
        }
        
        if(S[i]=='A'||S[i]=='?'){
            dp[i+1][1]+=dp[i][0];
        }
        if(S[i]=='B'||S[i]=='?'){
            dp[i+1][2]+=dp[i][1];
        }
        if(S[i]=='C'||S[i]=='?'){
            dp[i+1][3]+=dp[i][2];
        }

        REP(j,4){
            dp[i+1][j]%=MOD;
        }
        
    }
    cout<<dp[N][3]<<endl;
}