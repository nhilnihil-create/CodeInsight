#include <bits/stdc++.h>
#define cinf(n,x) for(int i=0;i<(n);i++)cin>>x[i];
#define ft first
#define sc second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(v) (v).begin(),(v).end()
#define LB(a,x) lb(all(a),x)-a.begin()
#define UB(a,x) ub(all(a),x)-a.begin()
#define mod 1000000007
#define FS fixed<<setprecision(15)
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<n;i++)
const double pi=3.141592653589793;
template<class T> using V=vector<T>;
using Graph = vector<vector<int>>;
using P=pair<ll,ll>;
typedef unsigned long long ull;
typedef long double ldouble;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

const ll INF=1e18;

class UnionFind{
public:
    vector<ll> par,num;

    int find(ll v){
        return (par[v]==v)? v: (par[v]=find(par[v]));
    }
    explicit UnionFind(ll N):par(N),num(N,1){
        iota(par.begin(),par.end(),0);
    }
    void unite(ll u,ll v){
        u=find(u),v=find(v);
        if(u==v)return ;
        if(num[u]<num[v])swap(u,v);
        num[u] += num[v];
        par[v] = u;
    }
    bool same(ll u,ll v){
        return find(u) == find(v);
    }
    bool ispar(ll v){
        return v=find(v);
    }
    ll size(ll v){
        return num[find(v)];
    }
};

int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    ll n,m;
    cin>>n>>m;
    V<ll> a(m),b(m);
    UnionFind G(n);
    rep(i,m){
        cin>>a[i]>>b[i];
        a[i]--;b[i]--;
    }
    ll sum=n*(n-1)/2;
    V<ll> ans;
    for(ll i=m-1;i>=0;i--){
        ans.push_back(sum);
        if(G.find(a[i])==G.find(b[i])){
            G.unite(a[i],b[i]);
        }else{
            sum-=G.size(a[i])*G.size(b[i]);
            G.unite(a[i],b[i]);
        }
    }
    reverse(all(ans));
    for(ll cur:ans) cout<<cur<<'\n';
}
//ペナルティ出しても焦らない　ACできると信じろ！！！
//どうしてもわからないときはサンプルで実験　何か見えてくるかも
//頭で考えてダメなら紙におこせ！！
/*
V,P(大文字)使用不可
乗算などの際にオーバーフローに注意せよ！
(適切にmodをとれ　にぶたんで途中で切り上げろ)
制約をよく読め！
{
    ・全探索できるなら全探索しろ
    ・異常な制約ならそこに注目
}
stringの計算量(扱い)注意
コーナー注意！(特に数値が小さいものについては要検証)
N行出力のときは'¥n'
グリッド上では行先が範囲内におさまるかif文で確認(RE注意)
if文ではちゃんと比較演算子==を使え('='でもエラー出ない)
配列(vector)の大きさが0か1以上かで場合分けせよ(RE注意)
(vector<int> a(m)でm==0というものはできない)
modはなるべく最後に取れ！
doubleを扱うときには(abs)ではなく'fabs'!!!
*/