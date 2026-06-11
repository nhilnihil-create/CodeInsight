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
    int D;
    ll G;
    cin>>D>>G;
    vector<ll> p(D),c(D);
    REP(i,D) cin>>p[i]>>c[i];
    ll ans=INF;
    REP(bit,1<<D){
        ll score=0;
        ll num=0;
        bool ok=false;
        REP(i,D){
            ll mask=1<<i;
            if(mask&bit){
                score+=p[i]*100*(i+1)+c[i];
                num+=p[i];
            }
        }
        if(score>=G){
            ans=min(ans,num);
        }
        REPD2(i,D-1,-1){
            ll mask=1<<i;
            if(mask&bit) continue;
            REP(j,p[i]){
                score+=100*(i+1);
                num++;
                if(score>=G){
                    ok=true;
                    break;
                }
            }
            if(ok) break;
        }
        if(ok){
            ans=min(ans,num);
        }
        
    }
    cout<<ans<<endl;
}