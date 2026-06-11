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

//省略
using vi  = vector<int>;
using vii = vector<vector<int>>;
using vl  = vector<ll>;
using vll = vector<vector<ll>>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

int main(){
    ll N,K;
    cin>>N>>K;
    vl a(N);
    vl sum(N+1,0);
    vl b(N*N,0);
    REP(i,N) cin>>a[i];
    REP(i,N){
        sum[i+1]=sum[i]+a[i];
    }
    ll idx=0;
    REP(l,N){
        REP2(r,l+1,N+1){
            b[idx]=sum[r]-sum[l];
            idx++;
        }
    }

    vector<bool> ok(N*N,true);
    ll ans=0;
    REPD2(i,58,-1){
        ll mask=1LL<<i;
        ll cnt=0;
        REP(j,idx){
            if(!ok[j]) continue;
            if(mask&b[j]) cnt++;
        }

        if(cnt>=K){
            ans+=pow(2,i);
            REP(j,idx){
                if(!ok[j]) continue;
                if(!(mask&b[j])) ok[j]=false;
            }
        }
    }
    cout<<ans<<endl;
}