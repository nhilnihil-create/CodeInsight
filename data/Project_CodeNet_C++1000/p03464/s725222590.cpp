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
    ll K;
    cin>>K;
    vector<ll> A(K);
    REP(i,K) cin>>A[i];
    ll x1,x2;
    x1=2;
    x2=3;
    REP(i,K-1){
        x1=max(((x1-1)/A[K-2-i]+1)*A[K-2-i],x1);
        x2=(1+x2/A[K-2-i])*A[K-2-i]-1;
    }
    

    if(x1>x2||A[K-1]!=2){
        cout<<-1<<endl;
    }else{
        cout<<x1<<" "<<x2<<endl;
    }
    
}