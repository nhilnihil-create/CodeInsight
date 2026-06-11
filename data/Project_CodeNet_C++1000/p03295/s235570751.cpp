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
using namespace std;
using P = pair<int,int>;
using ll = long long;
const int INF = 100000;
const int MAX_N = 1001001001;

int n,m;
vector<P> ran; 

bool comp(P a,P b){
    if(a.second != b.second){
        return a.second < b.second;
    }else{
        return a.first < b.first;
    }
}

int main(){
    cin >> n  >> m;
    int a,b ;
    rep(i,m){
        cin >> a >>b;
        ran.push_back(make_pair(a,b));
    }

    sort(ran.begin(),ran.end(),comp);

    int ans = 1;
    int cur = ran[0].second;

    rep(i,m){
        if(ran[i].first < cur) continue;
        ans++;
        cur = ran[i].second;
    }


    cout << ans << endl;



}
