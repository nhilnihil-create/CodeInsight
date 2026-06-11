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
#define sar(a,n) {cout<<#a<<":";rep(pachico,n)cout<<" "<<a[pachico];cout<<endl;}

using namespace std;

template<typename S,typename T>auto&operator<<(ostream&o,pair<S,T>p){return o<<"{"<<p.fi<<","<<p.se<<"}";}
template<typename T>auto&operator<<(ostream&o,set<T>s){for(auto&e:s)o<<e<<" ";return o;}
template<typename S,typename T,typename U>
auto&operator<<(ostream&o,priority_queue<S,T,U>q){while(!q.empty())o<<q.top()<<" ",q.pop();return o;}
template<typename K,typename T>auto&operator<<(ostream&o,map<K,T>&m){for(auto&e:m)o<<e<<" ";return o;}
template<typename T>auto&operator<<(ostream&o,vector<T>v){for(auto&e:v)o<<e<<" ";return o;}
void ashow(){cout<<endl;}template<typename T,typename...A>void ashow(T t,A...a){cout<<t<<" ";ashow(a...);}
template<typename S,typename T,typename U>
struct TRI{S fi;T se;U th;TRI(){}TRI(S f,T s,U t):fi(f),se(s),th(t){}
bool operator<(const TRI&_)const{return(fi==_.fi)?((se==_.se)?(th<_.th):(se<_.se)):(fi<_.fi);}};
template<typename S,typename T,typename U>
auto&operator<<(ostream&o,TRI<S,T,U>&t){return o<<"{"<<t.fi<<","<<t.se<<","<<t.th<<"}";}

typedef pair<ll, ll> P;

const int MAX_N = 100005;

vector<int> G[MAX_N];
ll D;

void dfs(int u, int p, int d){
    D += d;
    for(int v : G[u]){
        if(v != p) dfs(v, u, d+1);
    }
}

unordered_map<ll, int> mp;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    set<P> st;
    ll ch = 0;
    rep(i,n){
        ll d;
        cin >> d;
        if(i == 0) ch = d;
        mp[d] = i;
        st.insert(P(d, 1));
    }
    vector<pair<int, int> > vec;
    while(len(st) > 1){
        auto p = *(--st.end());
        st.erase(--st.end());
        auto it = st.lower_bound(P(p.fi+2*p.se-n, -INF));
        if(it->fi != p.fi+2*p.se-n){
            cout << "-1\n";
            return 0;
        }
        G[mp[p.fi]].pb(mp[it->fi]);
        G[mp[it->fi]].pb(mp[p.fi]);
        vec.emplace_back(mp[p.fi], mp[it->fi]);
        P nw = P(it->fi, it->se + p.se);
        st.erase(it);
        st.insert(nw);
    }
    dfs(0, -1, 0);
    if(D != ch){
        cout << "-1\n";
        return 0;
    }
    rep(i,n-1){
        cout << vec[i].fi+1 << " " << vec[i].se+1 << "\n";
    }
    return 0;
}
