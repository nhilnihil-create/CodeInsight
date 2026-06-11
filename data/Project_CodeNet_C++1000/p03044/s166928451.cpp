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
    vector<vector<pair<ll, ll>>> t(n+1);
    REP(i, n-1){
        ll u, v, w;
        cin >> u >> v >> w;
        t[u].PB(MP(v, w));
        t[v].PB(MP(u, w));
    }
    queue<ll> q;
    vector<ll> depth(n+1, -1), ans(n+1);
    ll start = 1;
    q.push(start);
    depth[start] = 0;
    while(q.empty() != true){
        ll v = q.front();
        q.pop();
        for(auto x : t[v]){
            if(depth[x.F] == -1){
                depth[x.F] = depth[v] + x.S;
                ans[x.F] = (ans[v] + x.S) % 2;
                q.push(x.F);
            }
        }
    }
    REP(i, n){
        cout << ans[i+1] << endl;
    }
    return 0;
}