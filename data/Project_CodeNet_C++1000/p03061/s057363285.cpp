#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

//マクロ
//forループ関係
//引数は、(ループ内変数,動く範囲)か(ループ内変数,始めの数,終わりの数)、のどちらか
//Dがついてないものはループ変数は1ずつインクリメントされ、Dがついてるものはループ変数は1ずつデクリメントされる
#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)
//xにはvectorなどのコンテナ
#define ALL(x) x.begin(),x.end() //sortなどの引数を省略したい
#define SIZE(x) ll(x.size()) //sizeをsize_tからllに直しておく
//定数
#define INF 1000000000000 //10^12:極めて大きい値,∞
#define MOD 1000000007 //10^9+7:合同式の法
#define MAXR 100000 //10^5:配列の最大のrange(素数列挙などで使用)
//略記
#define PB emplace_back //vectorヘの挿入
#define MP make_pair //pairのコンストラクタ
#define F first //pairの一つ目の要素
#define S second //pairの二つ目の要素
#define Umap unordered_map
#define Uset unordered_set

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    REP(i, n) cin >> a[i];
    vector<ll> dpl(n), dpr(n);
    dpl[0] = a[0];
    REP(i, n-1) dpl[i+1] = __gcd(dpl[i], a[i]);
    dpr[n-1] = a[n-1];
    REPD(i, n-1) dpr[i] = __gcd(dpr[i+1], a[i+1]);
    ll ans = max(dpl[n-1], dpr[0]);
    for(ll i = 1; i < n-1; i++) ans = max(ans, __gcd(dpl[i], dpr[i]));
    cout << ans;
    return 0;
}