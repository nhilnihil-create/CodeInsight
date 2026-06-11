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

ll ryuka(ll num){
    if(num == 0){
        return 2;
    }else if(num == 1){
        return 1;
    }
    return ryuka(num-2) + ryuka(num-1);
}

int main() {
    ll N;
    cin >> N;
    vector<ll> L(N+1);

    L[0] = 2;
    L[1] = 1;
    for(ll i=2;i<L.size();i++){
        L[i] = L[i-2] + L[i-1];
    }

    cout << L[N] << endl;
}
