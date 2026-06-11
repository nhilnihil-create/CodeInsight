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
    ll M,K;
    cin>>M>>K;
    bool ok=false;
    ll idx;
   
    if(K==0){
        REP(i,pow(2,M)){
            cout<<i<<" "<<i;
            if(i!=pow(2,M)-1){
                cout<<" ";
            }else{
                cout<<endl;
            }
        }
    }else if(K>=pow(2,M)||M==1){
        cout<<-1<<endl;
    }else{
        deque<ll> ans;
        ans.push_back(K);
        REP(i,pow(2,M)){
            if(i==K) continue;
            ans.push_front(i);
            ans.push_back(i);
        }
        ans.push_back(K);
        REP(i,ans.size()){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }else{
                cout<<endl;
            }
        }    
    }
    // if(K>=pow(2,M)){
    //     cout<<-1<<endl;
    // }else{

    // }
}