#include<algorithm>//sort,二分探索,など
#include<bitset>//固定長bit集合
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

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define erep(i,n) for (int i = 0; i <= (n); ++i)
#define brep(i,n) for (int i = n; i >= 0; i--)
using namespace std;
using P = pair<int,int>;
using ll = long long;
const int INF = 100005;
const int MAX_N = 200005;

int dp[MAX_N];

int main(){
    int n;
    cin >> n;
    rep(i,MAX_N){
        dp[i] = INF;
    }
    dp[0]=0;

    rep(i,n){
        for(int pow6=1;pow6 <=n; pow6*=6){
            dp[i+pow6] = min(dp[i+pow6],dp[i]+1);
        }
        for(int pow9=1; pow9 <=n;pow9*=9){
            dp[i+pow9] = min(dp[i+pow9],dp[i]+1);
        }
    }

    cout << dp[n] << endl;
    
}

