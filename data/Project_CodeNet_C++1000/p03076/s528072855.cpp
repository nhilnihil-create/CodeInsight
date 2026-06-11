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

ll adjust(ll num){
    while (num % 10 != 0){
        num++;
    }
    return num;
}

int main() {
    vector<ll> ryouri(5);
    rep(i,5){
        cin >> ryouri[i];
    }
    sort(ryouri.begin(),ryouri.end());
    ll ans=LLONG_MAX;
    do{
        ll a = adjust(ryouri[0]);
        ll b = adjust(a+ryouri[1]);
        ll c = adjust(b+ryouri[2]);
        ll d = adjust(c+ryouri[3]);
        ll result = d + ryouri[4];
        ans = min(ans,result);

    }while(next_permutation(ryouri.begin(),ryouri.end()));//辞書順で次の順列が存在すれば真

    cout << ans << endl;

}
