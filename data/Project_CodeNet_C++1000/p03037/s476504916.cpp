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
typedef long double lb; 

#define rep(i,n) for(ll i=0;i<(ll)(n);i++)


int main() {
    ll N,M;
    cin >> N >> M;
    vector<ll> L(M),R(M);
    rep(i,M){
        cin >> L[i] >> R[i];
    }

    ll maxValue=LLONG_MAX,minValue=0;
    rep(i,M){
        minValue = max(minValue,L[i]);
        maxValue = min(maxValue,R[i]);
    }

    //cout << maxValue << minValue << endl;
    ll ans=0;
    rep(i,N+1){
        if(minValue <= i+1 && i+1 <= maxValue){
            ans++;
        }
    }
    cout << ans << endl;

}
