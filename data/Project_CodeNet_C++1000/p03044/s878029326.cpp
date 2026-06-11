#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<vector>
#include<utility>
#include<queue>
#include<deque>
#include<stack>
#include<set>
#include<map>
#include<bitset>
#include<string>
#include<functional>
#define rep(i,n,m) for(int i=(n);i<(int)(m);i++)
#define reps(i,n,m) for(int i=(n);i<=(int)(m);i++)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define SZ(x) ((int)(x).size())
#define pb push_back
#define fs first
#define sc second
#define lb lower_bound
#define ub upper_bound
#define LB(a,x) lb(all(a), x) - a.begin()
#define UB(a,x) ub(all(a), x) - a.begin()
#define printfdouble(x) printf("%.20f\n",(x))
#define chartoint(c) (int)((c) - '0')
#define chartoll(c) (long long)((c) - '0')
#define MOD 1000000007
#define itn int
#define enld endl
#define ednl endl
#define icn cin
#define cotu cout
#define Endl endl
#define stirng string
using namespace std;
typedef long long ll;
const double pi = 3.141592653589793;
using Graph = vector<vector<int>>;
template<class T> bool chmax(T &a, const T &b){if(a<b){a=b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b){if(b<a){a=b; return 1;} return 0;}
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

struct edge{
    ll to;
    ll cost;
};

const ll INF = 1e18;

class Dijkstra {

public:
        vector<vector<edge>> graph; 
        vector<ll> dist;
        vector<ll> prev;


        Dijkstra(ll N){
            graph.resize(N);
            dist.resize(N, INF);
            prev.resize(N, -1);
        }

        void add_path(ll from, ll to, ll cost){
            graph[from].push_back({to, cost});
        }

        void solve(ll s){
            priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> que;
            dist[s] = 0;
            que.push({0,s});

            while(!que.empty()){
                pair<ll,ll> v = que.top();
                que.pop();
                if(dist[v.second] < v.first) continue;
                rep(i,0,SZ(graph[v.second])){
                    edge e = graph[v.second][i];
                    if(dist[e.to] > dist[v.second] + e.cost){
                        dist[e.to] = dist[v.second] + e.cost;
                        prev[e.to] = v.second;
                        que.push({dist[e.to], e.to});
                    }
                }
            }
        }

        ll get_cost(ll v){
            return dist[v];
        }

        vector<ll> get_path(ll goal){
            vector <ll> path;
            for(ll cur = goal; cur != -1; cur = prev[cur]) path.push_back(cur); 
            reverse(all(path));
            return path;
        }
};


int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    ll N; cin >> N;
    Dijkstra G(N);
    rep(i,0,N-1){
        ll u,v,w; cin >> u >> v >> w;
        u--; v--;
        G.add_path(u,v,w);
        G.add_path(v,u,w);
    }

    G.solve(0);

    rep(i,0,N){
        if(G.get_cost(i) % 2 == 0){
            cout << 0 << enld;
        }else{
            cout << 1 << ednl;
        }
    }

    return 0;
}