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

ll KetaSum(string num){
    ll sum=0;
    rep(i,num.size()){
        sum += num[i] - '0';
    }
    return sum;
}

int main() {
    ll N,A,B;
    cin >> N >> A >> B;

    ll resultSum=0;
    rep(i,N+1){
        ll ketaSum = KetaSum(to_string(i));
        if(A <= ketaSum && ketaSum <= B){
            resultSum += i;
        }
    }

    cout << resultSum << endl;
}

