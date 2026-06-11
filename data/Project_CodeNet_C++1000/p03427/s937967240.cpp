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

    ll sum = 0, ketaNum = 0,lastNum=0;
    while(N){
        ll dig = N % 10;
        sum = sum + dig;
        lastNum = N;
        N = N / 10;
        ketaNum++;
    }

    ll ans=0;
    if((sum-lastNum) == 9*(ketaNum-1)){
        ans = lastNum+(9*(ketaNum-1));
    }else{
        ans = lastNum+(9*(ketaNum-1))-1;
    }

    // cout << lastNum << endl;
    // cout << ketaNum << endl;
    // cout << sum-lastNum << endl;

    cout << ans << endl;
}


