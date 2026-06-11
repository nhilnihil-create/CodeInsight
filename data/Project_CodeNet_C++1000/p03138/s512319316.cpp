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
    ll N,K;
    cin>>N>>K;
    vector<ll> A(N);
    vector<ll> bit(60,0);
    
    REP(i,N) cin>>A[i];

    ll tmp=0;
    REP(i,60){
        ll mask = 1LL<<i;
        REP(j,N){
            if(mask&A[j]) bit[i]++;
        }
    }

    ll ans=tmp;
    REP2(i,-1,60){
        if(i!=-1&&!(K&(1LL<<i))) continue;
        tmp=0;
        REP(j,60){
            ll mask=1LL<<j;
            if(j<i){
                tmp+=mask*max(N-bit[j],bit[j]);
            }

            if(j==i){
                tmp+=mask*bit[j];
            }

            if(j>i){
                if(K&mask){
                    tmp+=mask*(N-bit[j]);
                }else{
                    tmp+=mask*bit[j];
                }
            }
        }

        ans=max(tmp,ans);
    }
    cout<<ans<<endl;
}