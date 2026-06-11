#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for(int i=0; i<n; i++)
#define REPi(i, a, b) for(int i=int(a); i<int(b); i++)
#define MEMS(a,b) memset(a,b,sizeof(a))
#define mp make_pair
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll MOD = 1e9+7;

class UnionFind{
    ll n;
    vector<ll> par;
    vector<ll> depth;

    public:

    UnionFind(ll num){
        n = num;
        par.resize(n);
        REP(i,n) par[i] = i;
        depth.resize(n, 1);
    }

    void unite(ll x, ll y){
        x = find(x);
        y = find(y);
        if(x == y) return;

        if(depth[x] >= depth[y]){
            par[y] = x;
            if(depth[x] == depth[y])
                depth[x]++;
        }
        else{
            par[x] = y;
        }
    }
    
    ll find(ll x){
        if(x == par[x])
            return x;
        else
            return par[x] = find(par[x]);
    }
};

int main(){
    ll N, M;
    cin >> N >> M;

    UnionFind uni(N);
    REP(i,M){
        ll x, y, z;
        cin >> x >> y >> z;
        x--, y--;
        uni.unite(x, y);
    }

    ll ans = 0;
    REP(i,N){
        if(uni.find(i) == i)
            ans++;
    }

    cout << ans << endl;
    return 0;
}
