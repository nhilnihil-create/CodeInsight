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
    set<pair<ll,ll>> st;
    

    if(N%2==0){
        REP2(i,1,N+1){
            REP2(j,1,N+1){
                if(i==j||i+j==N+1) continue;
                ll a=min(i,j);
                ll b=max(i,j);
                st.insert(make_pair(a,b));
            }
        }
    }else{
        REP2(i,1,N){
            ll a=i;
            ll b=N;
            st.insert(make_pair(a,b));
        }
        REP2(i,1,N){
            REP2(j,1,N){
                if(i==j||i+j==N) continue;
                ll a=min(i,j);
                ll b=max(i,j);
                st.insert(make_pair(a,b));
            }
        }
    }
    

    cout<<st.size()<<endl;
    for(auto itr=st.begin();itr!=st.end();itr++){
        cout<<itr->first<<" "<<itr->second<<endl;
    }
}