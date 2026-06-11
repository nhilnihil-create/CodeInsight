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

const double N_MAX=100;
const int dt_MAX=40010;
vector<double> t(N_MAX+2);
vector<double> v(N_MAX+2);

int main(){
    double N;
    cin>>N;
    REP(i,N) cin>>t[i+1];
    REP(i,N) cin>>v[i+1];
    v[0]=0;
    v[N+1]=0;
    t[0]=0;
    REP(i,N){
        t[i+1]+=t[i];
    }
    t[N+1]=20020;
    double dt=0.50;
    double ans=0;
    REP(i,dt_MAX){
        double timea=dt*i;
        double timeb=timea+dt;
        if(timea>=t[N]) break; 
        double va=200;
        double vb=200;
        
        REP(j,N+2){
            double l;
            if(j==0) l=t[0];
            else l=t[j-1];
            double r=t[j];
            if(timea<=l){
                va=min(va,v[j]+(l-timea));
            }else if(timea>=l&&timea<=r){
                va=min(va,v[j]);
            }else{
                va=min(va,v[j]+(timea-r));
            }

            if(timeb<=l){
                vb=min(vb,v[j]+(l-timeb));
            }else if(timeb>=l&&timeb<=r){
                vb=min(vb,v[j]);
            }else{
                vb=min(vb,v[j]+(timeb-r));
            }
        }
        ans+=0.25*(va+vb);
    }
    printf("%.4f\n",ans);

}