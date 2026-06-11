#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
using ll= long long;
using ld= long double;
using P =pair<ll,ll>;


//マクロ
//forループ関係
//引数は、(ループ内変数,動く範囲)か(ループ内変数,始めの数,終わりの数)、のどちらか
//Dがついてないものはループ変数は1ずつインクリメントされ、Dがついてるものはループ変数は1ずつデクリメントされる
#define REP(i,n) for(ll i=0;i<=(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
//xにはvectorなどのコンテナ
#define ALL(x) (x).begin(),(x).end() //sortなどの引数を省略したい
#define sort(a) sort(ALL(a))//sortの省略
#define SIZE(x) ((ll)(x).size()) //sizeをsize_tからllに直しておく
#define MAX(x) *max_element(ALL(x)) //最大値を求める
#define MIN(x) *min_element(ALL(x)) //最小値を求める
//定数
#define INF 1000000000000 //10^12:極めて大きい値,∞
#define MOD 10000007 //10^9+7:合同式の法
#define MAXR 100000 //10^5:配列の最大のrange(素数列挙などで使用)
//略記
#define in(T, x) T x;cin >> x;//Tは型,xが入力値
#define vec(T,a,n,x) vector<T> a(n,x);
#define vec2(T,a,n,m) vector<vector<T>> a(n,vector<T>(m));
#define PB push_back //vectorヘの挿入
#define MP make_pair //pairのコンストラクタ
#define F first //pairの一つ目の要素
#define S second //pairの二つ目の要素
#define out(x) cout << x << endl//出力
#define bout(b) if(b){out("Yes");}else{out("No");}//真偽問題に対する出力
#define ain(T, a, n) vector<T> a(n);REP(i, n){cin >> a[i];}//配列の宣言と入力
#define a2in(T1, a, T2, b, n) vector<T1> a(n);vector<T2> b(n);REP(i, n){cin >> a[i] >> b[i];}//2つの配列を同時宣言、入力

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }//dp表とかで最大値更新するやつ
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }//最小値更新


signed main(){
  int cnt=0;
  in(ll,a);in(ll,b);in(ll,c);in(ll,x);
  x/=50;
  REP(i,a){
    REP(j,b){
      REP(k,c){
        if(10*i+2*j+k==x)cnt++;
      }
    }
  }
  out(cnt);
  
   

}
