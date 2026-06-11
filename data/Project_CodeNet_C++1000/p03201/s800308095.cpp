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
    ll N;
    cin>>N;
    vector<ll> A(N);
    map<ll,ll> mp;
    REP(i,N){
        cin>>A[i];
        mp[A[i]]++;

    }
    sort(ALL(A),greater<ll>());
    ll ans=0;
    vector<ll> num(33,0);
    REP(i,33) num[i]=pow(2,i);
    REP(i,N){
        if(mp[A[i]]<=0) continue;
        REPD2(j,32,-1){
            if(num[j]<=A[i]) break;
            if(mp[num[j]-A[i]]>0){
                if(!(mp[num[j]-A[i]]==1&&num[j]-A[i]==A[i])){
                    mp[num[j]-A[i]]--;
                    mp[A[i]]--;
                    ans++;
                    break;
                }
            }
        }
    }
    cout<<ans<<endl;
}