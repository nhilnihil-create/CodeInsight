#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
struct UnionFind{
    vector<int> d;
    UnionFind(int n) : d(n,-1) {}
    //根なら、-サイズを格納それ以外は、親を格納
    int find(int x){
        if(d[x] < 0) return x;
        return d[x] = find(d[x]); //経路縮約
    }
    bool unite(int x,int y){
        //二つ頂点を持ってくる
        x = find(x);
        y = find(y);
        if(x == y) return false;//根が一致するなら何もしない
        if(d[x] > d[y]) swap(x,y);
        //ex:d[x]=-5,d[y]=-2
        //小さい方が、大きい方に引っ付く
        d[x] += d[y];//この場合、yがxにくっつく
        d[y] = x;
        return true;
    }
    bool same(int x,int y) {return find(x) == find(y);}
    int size(int x) {return -d[find(x)];}
};
int main(){
    cout << fixed << setprecision(10);
    ll n,m;
    cin >> n >> m;
    vector<int> a(m),b(m);
    rep(i,m) cin >> a[i] >> b[i];
    rep(i,m){
        a[i]--; b[i]--;
    }
    UnionFind uf(n);
    vector<ll> ans;
    ll now = n*(n-1)/2;
    rep(i,m){
        ans.push_back(now);
        int aa = a[m-i-1], bb = b[m-i-1];
        if(uf.same(aa,bb)){
            continue;
        }
        ll sa = uf.size(aa)*uf.size(bb);
        now -= sa;
        uf.unite(aa,bb);
    }
    reverse(ans.begin(),ans.end());
    for(auto u : ans) cout << u << endl;
    return 0;
}