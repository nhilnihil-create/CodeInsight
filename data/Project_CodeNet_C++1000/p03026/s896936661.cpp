#include<bits/stdc++.h>
using namespace std;
//#include<boost/multiprecision/cpp_int.hpp>
//using boost::multiprecision::cpp_int;

#define int long long
#define cint cpp_int
#define endl "\n"
#define REP(i,a,n) for(int i=a;i<n;++i)
#define REPR(i,a,n) for(int i=a;i>n;--i)
#define RUP(a,b) (((a)+(b)-1)/(b))
#define ALL(v) (v).begin(),(v).end()
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define MOD 1000000007
#define INF LLONG_MAX/2
#define PI acos(-1.0)

typedef long long ll;
typedef pair<int,int> Pii;
typedef tuple<int,int,int> Tiii;
typedef vector<int> Vi;
typedef vector<Vi> VVi;
typedef vector<Pii> VPii;
typedef vector<string> Vs;

template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T> void YesNo(T a) {cout<<(a?"Yes":"No")<<endl;}
template<class T> void YESNO(T a) {cout<<(a?"YES":"NO")<<endl;}
void vout(Vi &v){for(int i=0;i<(v).size();i++) cout<<v[i]<<" ";cout<<endl;}
void vvout(VVi &v){for(int i=0;i<(v).size();i++) vout(v[i]);}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int lcm(int a,int b){return a/gcd(a,b)*b;}
int mypow(int x, int n, int m){if(n==0)return 1;if(n%2==0)return mypow(x*x%m,n/2,m);else return x*mypow(x,n-1,m)%m;}
int digit(int k,int i){string s = to_string(k);return s[s.size()-i]-'0';}
void uniq(Vi &v){sort(v.begin(),v.end()); v.erase(unique(v.begin(),v.end()),v.end());}
int ctoi(char c){if(c>='0'&&c<='9'){return c-'0';}return 0;}
Vi accum(Vi v){Vi ret((v).size());ret[0]=v[0];REP(i,1,(v).size()) ret[i]=ret[i-1]+v[i];return ret;}
bool comp(Pii a,Pii b){
    if(a.second != b.second) return a.second<b.second;
    else return a.first<b.first;
}

Vi c;

struct edge{int to,cost;};
struct graph{
    int N;  
    vector< vector<edge> > G;
    Vi dist;
    graph(int n){
        init(n);
    }
    void init(int n){
        N = n;
        G.resize(N);
        dist.resize(N);
        REP(i,0,N){
            dist[i] = INF;
        }
    }
    void add_edge(int s,int t,int cost=1){
        edge e;
        e.to = t, e.cost = cost;
        G[s].push_back(e);
    }
    void bfs(int s){
        REP(i,0,N){
            dist[i] = 0;
        }
        int cost=1;
        dist[s]=c[0];
        queue<int> q;
        q.push(s);
        while(!q.empty()){
            int now=q.front();q.pop();
            for(auto e : G[now]){
                if(dist[e.to]==0){
                    dist[e.to] = c[cost];
                    cost++;
                    q.push(e.to);
                }
            }
        }
    }
    void dijkstra(int s){
        REP(i,0,N){
            dist[i] = INF;
        }
        dist[s] = 0;
        priority_queue<Pii,vector<Pii>,greater<Pii>> q;
        q.push(mp(s,0));
        while(!q.empty()){
            int now,nowdist;
            tie(now,nowdist) = q.top();q.pop();
            if(dist[now]<nowdist) continue;
            for(auto e : G[now]){
                if(dist[e.to]>dist[now]+e.cost){
                    dist[e.to] = dist[now]+e.cost;
                    q.push(mp(e.to,dist[e.to]));
                }
            }
        }
    }
    void bellman_ford(int s){
        REP(i,0,N){
            dist[i]=INF;
        }
        dist[s]=0;
        REP(i,0,N){
            REP(j,0,N){
                for(auto e : G[j]){
                    if(dist[e.to] > dist[j] + e.cost){
                        dist[e.to] = dist[j] + e.cost;
                        if(i==N-1){
                            //閉路発見！
                        }
                    }
                }
            }
        }
    }
};

signed main(){cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(12);
    int n;
    cin>>n;
    Vi a(n-1),b(n-1);
    REP(i,0,n-1){
        cin>>a[i]>>b[i];
        a[i]--; b[i]--;    
    }
    c.resize(n);
    REP(i,0,n) cin>>c[i];
    sort(ALL(c),greater<int>());

    graph G(n);

    REP(i,0,n-1){
        G.add_edge(a[i],b[i]);
        G.add_edge(b[i],a[i]);
    }

    G.bfs(0);
//    vout(c);
    int ans=0;
    REP(i,1,n) ans+=c[i];
    cout<<ans<<endl;
    REP(i,0,n) cout<<G.dist[i]<<" ";
    cout<<endl;

    return 0;
}
