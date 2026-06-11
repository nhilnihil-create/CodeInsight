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
int len;
int N;
ll ans;

const vector<int> G={0,3,5,7};

void dfs(vector<int> &A) {
    if (A.size() == len) {
        int cnt0=0;
        int cnt3=0;
        int cnt5=0;
        int cnt7=0;
        int tmp=0;
        for(int i=0;i<len;i++){
            tmp+=A[i]*pow(10,len-i-1);
            if(A[i]==0){
                if(cnt3>0||cnt5>0||cnt7>0){
                    cnt0++;
                }
            }
            if(A[i]==3) cnt3++;
            if(A[i]==5) cnt5++;
            if(A[i]==7) cnt7++;
        }
        if(cnt0>0||N<tmp) return;
        if(cnt3>0&&cnt5>0&&cnt7>0) ans++;
        return;
    }

    for (auto v:G) {
        A.push_back(v);
        dfs(A);
        A.pop_back();
    }
}


int main(){
    cin>>N;
    ans=0;
    int tmp=N;
    while(tmp>0){
        len++;
        tmp/=10;
    }
    vector<int> A;
    dfs(A);
    cout<<ans<<endl;
    
    
}