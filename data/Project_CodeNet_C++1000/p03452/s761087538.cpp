#include <bits/stdc++.h>
#define ll long long
#define INF 1000000005
#define MOD 1000000007
#define EPS 1e-10
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;--i)
#define srep(i,s,t) for(int i=(int)(s);i<(int)(t);++i)
#define each(a,b) for(auto (a): (b))
#define all(v) (v).begin(),(v).end()
#define len(v) (int)(v).size()
#define zip(v) sort(all(v)),v.erase(unique(all(v)),v.end())
#define cmx(x,y) x=max(x,y)
#define cmn(x,y) x=min(x,y)
#define fi first
#define se second
#define pb push_back
#define show(x) cout<<#x<<" = "<<(x)<<endl
#define spair(p) cout<<#p<<": "<<p.fi<<" "<<p.se<<endl
#define svec(v) cout<<#v<<":";rep(kbrni,v.size())cout<<" "<<v[kbrni];cout<<endl
#define sset(s) cout<<#s<<":";each(kbrni,s)cout<<" "<<kbrni;cout<<endl
#define smap(m) cout<<#m<<":";each(kbrni,m)cout<<" {"<<kbrni.first<<":"<<kbrni.second<<"}";cout<<endl

using namespace std;

typedef pair<int,int> P;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<P> vp;
typedef vector<string> vs;

const int MAX_N = 100005;

template<typename T> class Weighted_UnionFind
{
public:
    vector<int> par,nrank;
    vector<T> wd;
    int V;
    Weighted_UnionFind(int node_size){
        V = node_size;
        par.resize(V),wd.resize(V,0),nrank.resize(V,0);
        rep(i,V){
            par[i] = i;
        }
    }
    int find(int x){
        if(par[x] == x){
            return x;
        }else{
            int parent = find(par[x]);
            wd[x] += wd[par[x]];
            return par[x] = parent;
        }
    }
    T weight(int x){
        find(x);
        return wd[x];
    }
    void unite(int x,int y,T w){
        w += weight(x), w -= weight(y);
        x = par[x],y = par[y];
        if(x == y) return;
    	if(nrank[x] < nrank[y]){
            swap(x,y);
            w = -w;
        }
        nrank[x] += (nrank[x] == nrank[y]);
        par[y] = x;
        wd[y] = w;
    }
    bool same(int x,int y){
        return find(x)==find(y);
    }
    T diff(int x,int y){
        return weight(y)-weight(x);
    }
};


int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    Weighted_UnionFind<int> wu(n);
    rep(i,m){
        int l,r,d;
        cin >> l >> r >> d;
        --l,--r;
        if(wu.same(l,r)){
            if(wu.diff(l,r) != d){
                cout << "No\n";
                return 0;
            }
        }else{
            wu.unite(l,r,d);
        }
    }
    cout << "Yes\n";
    return 0;
}
