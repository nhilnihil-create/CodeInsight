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
    ll N,D,X;
    cin >> N >> D >> X;
    
    vector<ll> A(N);
    rep(i,N){
        cin >> A[i];
    }

    ll ans=0;
    rep(i,N){
        ll j=0,day=0;
        while(day<D){
            day = j*A[i]+1;
            if(day > D){
                break;
            }
            j++;
            ans++;          
        }        
    }
    ans += X;

    cout << ans << endl;

}
