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
    int N;
    cin>>N;
    vector<ll> A(N);
    bool ok=true;
    ll ans=0;
    REP(i,N){
        cin>>A[i];
    }

    REP(i,N){
        if(i>0&&A[i]-A[i-1]>=2) ok=false;
        
        if(A[i]!=0) ans++;

        if(i>0&&A[i]!=(A[i-1]+1)){
            ll tmp=max(0LL,A[i]-1LL);
            ans+=tmp;
        }
    }

    if(A[0]!=0) ok=false;
    if(!ok){
        cout<<-1<<endl;
    }else{
        cout<<ans<<endl;
    }
}