#include <bits/stdc++.h>
using namespace std;
struct edge {
    int to;     // 辺の行き先
    int weight; // 辺の重み
    edge(int t, int w) : to(t), weight(w) { }
};
using Graph = vector<vector<int>>;
using dou =long double;
string yes="yes";
string Yes="Yes";
string YES="YES";
string no="no";
string No="No";
string NO="NO";

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
#define rep(i, n)         for(int i = 0; i < (int)(n); i++)
#define brep(n)           for(int bit=0;bit<(1<<n);bit++)
#define erep(i,container) for (auto i : container)
#define irep(i, n)        for(int i = n-1; i >= (int)0; i--)
#define rrep(i,m,n) for(ll i = m; i < (ll)(n); i++)
#define reprep(i,j,h,w) rep(i,h)rep(j,w)
#define all(x) (x).begin(),(x).end()
#define VEC(type,name,n) std::vector<type> name(n);rep(i,n)std::cin >> name[i];
#define pb push_back
#define pf push_front
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define itn int
#define mp make_pair
#define sum(a) accumulate(all(a),0ll)
#define keta fixed<<setprecision
#define vvector(name,typ,m,n,a)vector<vector<typ> > name(m,vector<typ> (n,a))
#define vvvector(name,t,l,m,n,a) vector<vector<vector<t> > > name(l, vector<vector<t> >(m, vector<t>(n,a)));
#define vvvvector(name,t,k,l,m,n,a) vector<vector<vector<vector<t> > > > name(k,vector<vector<vector<t> > >(l, vector<vector<t> >(m, vector<t>(n,a)) ));
#define case std::cout <<"Case #" <<qqq+1<<": "
#define res resize
#define as assign
#define ffor for(;;)
#define ppri(a,b) std::cout << a<<" "<<b << std::endl
#define pppri(a,b,c) std::cout << a<<" "<<b <<" "<< c<<std::endl
#define aall(x,n) (x).begin(),(x).begin()+(n)
 
typedef long long ll;
typedef pair<int,int> P;
//typedef long long T;
const int INF = 2000000000;
const ll INF64 = 922337203685477580ll;
const ll MOD = 1000000007ll;
const dou pi=3.141592653589793;

int main(){
    int n;
    std::cin >> n;
    std::vector<std::vector<int> >g(n) ;
    
    rep(i,n-1){
        int a,b;
        std::cin >> a>>b;
        a--;b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    VEC(int,c,n);
    sort(all(c),greater<int>());
    int mil=INF;
    rep(i,n){
        if(g[i].size()>1){
            mil=i;
            break;
        }
        
    }
    
    std::queue<int> q;
    std::vector<int> di(n,-1);
    di[mil]=0;
    q.push(mil);
    int dd=0;
    while(!q.empty()){
        int d=q.front();
        erep(ii,g[d]){
            if(di[ii]==-1){
                di[ii]=di[d]+1;
                dd=max(dd,di[ii]);
                q.push(ii);
            }
        }
        q.pop();
    }
    std::vector<pair<int,int>> p(n);
    rep(i,n){
        p[i]=mp(di[i],i);
    }
    sort(all(p));
    std::vector<int> val(n);
   // rep(i,n)std::cout << c[i] << std::endl;
    rep(i,n){
        val[p[i].se]=c[i];
    }
    
    
    rep(i,n)di[i]=-1;
    di[mil]=0;
    ll ans=0;
    q.push(mil);
    while(!q.empty()){
        int d=q.front();
        erep(ii,g[d]){
            if(di[ii]==-1){
                di[ii]=di[d]+1;
                ans+=min(val[d],val[ii]);
                q.push(ii);
            }
        }
        q.pop();
    }
    std::cout << ans << std::endl;
    erep(i,val)std::cout << i << ' ';
    std::cout << std::endl;
    
}