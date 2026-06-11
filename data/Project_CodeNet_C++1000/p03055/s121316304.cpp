#include <bits/stdc++.h>
#define ll long long
#define INF 1000000005
#define MOD 1000000007
#define EPS 1e-10
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;--i)
#define srep(i,s,t) for(int i=(int)(s);i<(int)(t);++i)
#define each(a,b) for(auto& (a): (b))
#define all(v) (v).begin(),(v).end()
#define len(v) (int)(v).size()
#define zip(v) sort(all(v)),v.erase(unique(all(v)),v.end())
#define cmx(x,y) x=max(x,y)
#define cmn(x,y) x=min(x,y)
#define fi first
#define se second
#define pb push_back
#define show(x) cout<<#x<<" = "<<(x)<<endl
#define sar(a,n) cout<<#a<<":";rep(pachico,n)cout<<" "<<a[pachico];cout<<endl

using namespace std;

template<typename S,typename T>auto&operator<<(ostream&o,pair<S,T>p){return o<<"{"<<p.fi<<","<<p.se<<"}";}
template<typename T>auto&operator<<(ostream&o,set<T>s){for(auto&e:s)o<<e<<" ";return o;}
template<typename S,typename T,typename U>
auto&operator<<(ostream&o,priority_queue<S,T,U>q){while(!q.empty())o<<q.top()<<" ",q.pop();return o;}
template<typename K,typename T>auto&operator<<(ostream&o,map<K,T>&m){for(auto&e:m)o<<e<<" ";return o;}
template<typename T>auto&operator<<(ostream&o,vector<T>v){for(auto&e:v)o<<e<<" ";return o;}
void ashow(){cout<<endl;}template<typename T,typename...A>void ashow(T t,A...a){cout<<t<<" ";ashow(a...);}
template<typename S,typename T,typename U>
struct TRI{S fi;T se;U th;TRI(){}TRI(S f,T s,U t):fi(f),se(s),th(t){}};
template<typename S,typename T,typename U>
auto&operator<<(ostream&o,TRI<S,T,U>&t){return o<<"{"<<t.fi<<","<<t.se<<","<<t.th<<"}";}

typedef pair<int, int> P;
typedef pair<ll, ll> pll;
typedef TRI<int, int, int> tri;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<P> vp;
typedef vector<double> vd;
typedef vector<string> vs;

const int MAX_N = 200005;

class TreeDiameter
{
public:
    vector<vector<int> > G;
    vector<int> diameter;
    int V;
    TreeDiameter(int node_size){
        V = node_size;
        G.resize(V);
    }
    void add_edge(int u,int v){
        G[u].push_back(v),G[v].push_back(u);
    }
    void dfs(int u,int p,int d,int& far,int& mx){
        if(mx < d){
            far = u;
            mx = d;
        }
        for(int v : G[u]){
            if(v != p){
                dfs(v,u,d+1,far,mx);
            }
        }
    }
    bool redfs(int u,int p,const int t){
        if(u == t){
            return true;
        }
        for(int v : G[u]){
            if(v != p){
                diameter.push_back(v);
                if(redfs(v,u,t)){
                    return true;
                }else{
                    diameter.pop_back();
                }
            }
        }
        return false;
    }
    void solve(){
        int s,t,mx;
        mx = -1;
        dfs(0,-1,0,s,mx);
        mx = -1;
        dfs(s,-1,0,t,mx);
        diameter.push_back(s);
        redfs(s,-1,t);
    }
};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    TreeDiameter td(n);
    rep(i,n-1){
        int a,b;
        cin >> a >> b;
        td.add_edge(a-1, b-1);
    }
    td.solve();
    if(len(td.diameter) % 3 == 2){
        cout << "Second\n";
    }else{
        cout << "First\n";
    }
    return 0;
}
