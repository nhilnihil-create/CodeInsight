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
    int N,M;
    cin>>N>>M;
    vector<int> A(M);
    REP(i,M) cin>>A[i];
    vector<int> B={-1,2,5,5,4,5,6,3,7,6};
    map<int,int> mp;
    REP(i,M){
        mp[B[A[i]]]=max(mp[B[A[i]]],A[i]);
    }
    auto dp=make_vec<ll>(N+100,10);
    for(auto itr=mp.begin();itr!=mp.end();itr++){
        dp[itr->first][0]++;
        dp[itr->first][itr->second]++;
    }

    REP(i,N+1){
        if(dp[i][0]==0) continue;
        for(auto itr=mp.begin();itr!=mp.end();itr++){
            bool flag=false;
            if(dp[i][0]+1==dp[i+(itr->first)][0]){
                REPD2(j,9,0){
                    int tmp=dp[i][j];
                    if(j==(itr->second)) tmp++;
                    if(tmp>dp[i+(itr->first)][j]){
                        flag=true;
                        break;
                    }else if(tmp<dp[i+(itr->first)][j]){
                        break;
                    }
                }
            }
            if(dp[i][0]+1>dp[i+(itr->first)][0]||flag){
                REP(j,10){
                    dp[i+(itr->first)][j]=dp[i][j];
                }
                dp[i+(itr->first)][0]++;
                dp[i+(itr->first)][(itr->second)]++;
            }
        }
    }
    REPD2(i,9,0){
        REP(j,dp[N][i]) cout<<i;
    }
    cout<<endl;

    
    
}