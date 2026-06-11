#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;

typedef int _loop_int;
#define REP(i,n) for(_loop_int i=0;i<(_loop_int)(n);++i)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)
#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1;i>=(_loop_int)(a);--i)

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG2(x,y) cout<<#x<<": "<<x<<" "<<#y<<": "<<y<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(debugidx,v.size())cout<<" "<<v[debugidx];cout<<endl
#define DEBUG_ARR(v,n) cout<<#v<<":";REP(debugidx,n)cout<<" "<<v[debugidx];cout<<endl
#define ALL(a) (a).begin(),(a).end()

const ll MOD = 1000000007ll;

#define FIX(a) ((a)%MOD+MOD)%MOD

struct UnionFind {
  vector< int > data;
 
  UnionFind(int sz) {
    data.assign(sz, -1);
  }
 
  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return (false);
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return (true);
  }
 
  int find(int k) {
    if(data[k] < 0) return (k);
    return (data[k] = find(data[k]));
  }
 
  int size(int k) {
    return (-data[find(k)]);
  }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    ll n,m;
    cin>>n>>m;

    vector<pii> bridges(m);
    REP(i,m){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        bridges[i] = pii(a,b);
    }

    UnionFind uf(n);
    vl ans(m);
    ll now = (n*(n-1))/2;

    FORR(i,0,m){
        pii p = bridges[i];

        ans[i] = now;

        if(uf.find(p.first) != uf.find(p.second)){
            now -= uf.size(p.first) * uf.size(p.second);
        }

        uf.unite(p.first, p.second);  
    }

    REP(i,m){
        cout << ans[i] << endl;
    }
    
    return 0;
}