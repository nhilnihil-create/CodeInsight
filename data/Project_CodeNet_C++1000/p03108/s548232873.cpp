#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<queue>
#include<map>
#include<deque>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
typedef pair<int,int> P;

const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

struct UnionFind{
    vector<int> par;

    //コンストラクタ
    UnionFind(int N) : par(N) {
        for(int i=0;i<N;i++) par[i]=-1;
    }

    int root(int x){
        if(par[x]<0) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x,int y){
        int rx = root(x);
        int ry = root(y);
        if(rx==ry) return;

        if(size(rx)<size(ry)) swap(rx,ry);

        par[rx] += par[ry];
        par[ry] = rx;
    }

    bool same(int x,int y){
        int rx = root(x);
        int ry = root(y);
        return rx==ry;
    }

    int size(int x){
        return -par[root(x)];
    }

};


int main(){
    ll n,m;
    cin >> n >> m;
    //構造体名 オブジェクト名
    UnionFind tree(n);
    vector<ll> a(m),b(m);
    rep(i,m){
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
    }
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());

    vector<ll> ans(m);
    ans[0] = (ll)n*(n-1)/2;
    for(int i=1;i<m;i++){
        ans[i] = ans[i-1];
        ll n1 = a[i-1];
        ll n2 = b[i-1];
        if(!tree.same(n1,n2)) ans[i] -= (ll)tree.size(n1)*tree.size(n2);
        tree.unite(n1,n2);
    }

    for(int i=m-1;i>=0;i--){
        cout << ans[i] << endl;
    }
}