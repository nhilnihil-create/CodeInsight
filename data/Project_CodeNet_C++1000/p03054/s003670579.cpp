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
    int H,W,N;
    cin>>H>>W>>N;
    int sr,sc;
    cin>>sr>>sc;
    string S,T;
    cin>>S>>T;
    bool ok=true;
    vector<int> dp_L(2*N+1,0),dp_R(2*N+1,0),dp_U(2*N+1,0),dp_D(2*N+1,0);
    dp_L[0]=sc;
    dp_R[0]=sc;
    dp_U[0]=sr;
    dp_D[0]=sr;
    REP(i,2*N){
        dp_L[i+1]=dp_L[i];
        dp_R[i+1]=dp_R[i];
        dp_U[i+1]=dp_U[i];
        dp_D[i+1]=dp_D[i];
        
        if(i%2==0){//Takahshiのターン
            if(S[i/2]=='L'){
                dp_L[i+1]--;
            }
            if(S[i/2]=='R'){
                dp_R[i+1]++;
            }
            if(S[i/2]=='U'){
                dp_U[i+1]--;
            }
            if(S[i/2]=='D'){
                dp_D[i+1]++;
            }
        }else{
            if(T[i/2]=='R'&&dp_L[i+1]<W){
                dp_L[i+1]++;
            }
            if(T[i/2]=='L'&&dp_R[i+1]>1){
                dp_R[i+1]--;
            }
            if(T[i/2]=='D'&&dp_U[i+1]<H){
                dp_U[i+1]++;
            }
            if(T[i/2]=='U'&&dp_D[i+1]>1){
                dp_D[i+1]--;
            }
        }
        if(dp_L[i+1]<=0) ok=false;
        if(dp_R[i+1]>=W+1) ok=false;
        if(dp_U[i+1]<=0) ok=false;
        if(dp_D[i+1]>=H+1) ok=false;
        
    }
    
    

    if(ok) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}