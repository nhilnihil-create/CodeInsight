#include<algorithm>//sort,二分探索,など
#include<bitset>//固定長bit集合
#include<climits>//long long型の最大値(LLONG_MAX)など
#include<cmath>//pow,logなど
#include<complex>//複素数
#include<deque>//両端アクセスのキュー
#include<functional>//sortのgreater
#include<iomanip>//setprecision(浮動小数点の出力の誤差)
#include<iostream>//入出力
#include<iterator>//集合演算(積集合,和集合,差集合など)
#include<map>//map(辞書)
#include<numeric>//iota(整数列の生成),gcdとlcm(c++17)
#include<queue>//キュー
#include<set>//集合
#include<stack>//スタック
#include<string>//文字列
#include<unordered_map>//イテレータあるけど順序保持しないmap
#include<unordered_set>//イテレータあるけど順序保持しないset
#include<utility>//pair
#include<vector>//可変長配列

using namespace std;
typedef long long ll;
typedef long double ld;

#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

int main() {
    ll N;
    cin >> N;
    vector<vector<ll>> A(2,vector<ll>(N));
    rep(i,2){
        rep(j,N){
            cin >> A[i][j];
        }
    }

    ll ans=0;
    ll tmp=0;
    rep(i,N){
        ll result=0;
        ll j;
        for(j=0;j<=tmp;j++){
            result += A[0][j];
        }
        j -= 1;
        for(j=j;j<N;j++){
            result += A[1][j];
        }

        ans = max(ans,result);
        tmp++;
        
    }

    cout << ans << endl;
}
