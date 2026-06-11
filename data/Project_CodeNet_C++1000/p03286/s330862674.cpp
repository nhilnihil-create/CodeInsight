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
    vector<int> ans;
    if(N==0){
        cout<<0<<endl;
        return 0;
    }
    ll bit=60;
    while(bit>0){
        int dig=0;
 
        if((pow(4,bit/2)-1)/3+1<=N&&N<=(pow(4,(bit+1)/2)-1)/3){
            dig=1;
        }else if((-2*pow(4,(bit)/2)-1)/3<=N&&N<=-2*(pow(4,(bit-1)/2)-1)/3-1){
            dig=1;
        }


        if(!(dig==0&&ans.size()==0)){
            ans.push_back(dig);
        }
        N-=dig*pow(-2,bit-1);
        bit--;
    }
    REP(i,ans.size()){
        cout<<ans[i];
    }
    cout<<endl;
}