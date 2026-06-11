//
// Created by hide on 2020/05/15.
//

//参考：http://ehafib.hatenablog.com/entry/2015/12/23/164517
//インクルード(アルファベット順,bits/stdc++.hは使わない派閥)
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

using namespace std;
typedef long long ll;

//マクロ
//forループ関係
//引数は、(ループ内変数,動く範囲)か(ループ内変数,始めの数,終わりの数)、のどちらか
//Dがついてないものはループ変数は1ずつインクリメントされ、Dがついてるものはループ変数は1ずつデクリメントされる
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
//xにはvectorなどのコンテナ
#define ALL(x) (x).begin(),(x).end() //sortなどの引数を省略したい
#define SIZE(x) ((ll)(x).size()) //sizeをsize_tからllに直しておく
#define MAX(x) *max_element(ALL(x)) //最大値を求める
#define MIN(x) *min_element(ALL(x)) //最小値を求める
//定数
#define INF 1000000000000 //10^12:極めて大きい値,∞
#define MOD 1000000007 //10^9+7:合同式の法
#define MAXR 100000 //10^5:配列の最大のrange(素数列挙などで使用)
//略記
#define PB push_back //vectorヘの挿入
#define MP make_pair //pairのコンストラクタ
#define F first //pairの一つ目の要素
#define S second //pairの二つ目の要素

using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    map<int,int> v1,v2;
    REP(i,n/2) {
        int a,b;
        cin >> a >> b;
        v1[a]++; v2[b]++;
    }
    priority_queue<P> q1,q2;
    for(auto i:v1) q1.emplace(i.second,i.first);
    for(auto i:v2) q2.emplace(i.second,i.first);
    vector<P> p1(2,P(n/2,0)),p2(2,P(n/2,0));
    REP(i,2) if(!q1.empty()){ P p = q1.top(); q1.pop(); p1[i] = p;}
    REP(i,2) if(!q2.empty()){ P p = q2.top(); q2.pop(); p2[i] = p;}
    int ans = n;
    REP(i,2)REP(j,2) {
        if(p1[i].second == p2[j].second) continue;
        int res = n;
        if(p1[i].second!=0) res -= p2[j].first;
        if(p2[j].second!=0) res -= p1[i].first;
        ans = min(ans,res);
    }
    cout << ans << endl;
}