#include <iostream>
#include <algorithm>
#include <complex>
#include <utility>
#include <vector>
#include <string>
#include <queue>
#include <tuple>
#include <cmath>
#include <bitset>
#include <cctype>
#include <set>
#include <map>
#include <numeric>
#include <functional>
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(ll i=ll(a);i<ll(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()
#define PRINT(V) cout << V << "\n"
#define SORT(V) sort((V).begin(),(V).end())
#define RSORT(V) sort((V).rbegin(), (V).rend())
using namespace std;
using ll = long long;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
inline void Yes(bool condition){ if(condition) PRINT("Yes"); else PRINT("No"); }
template<class itr> void cins(itr first,itr last){
    for (auto i = first;i != last;i++){
        cin >> (*i);
    }
}
template<class itr> void array_output(itr start,itr goal){
    string ans = "",k = " ";
    for (auto i = start;i != goal;i++) ans += to_string(*i)+k;
    if (!ans.empty()) ans.pop_back();
    PRINT(ans);
}
ll gcd(ll a, ll b) {
    return a ? gcd(b%a,a) : b;
}
const int INF = 1e9;
const ll MOD = 1000000007;
typedef pair<ll,ll> P;
const ll MAX = 20000;
constexpr ll nx[4] = {1,0,-1,0};
constexpr ll ny[4] = {0,1,0,-1};
class Dijkstra{
    private:
        struct edge{
            int to,cost;
        };
        vector<vector<edge>> G;
        vector<int> d;
        int siz;
    public:
        Dijkstra(int n){
            G.resize(n);
            siz = n;
        }
        void add_edge(int from,int to,int cost){
            G[from].push_back(edge{to,cost});
        }
        vector<int> dijkstra(int s){
            priority_queue<P,vector<P>,greater<P>> q;
            d.assign(siz,INF);
            d[s] = 0;
            q.push(P(0,s));
            while(!q.empty()){
                P p = q.top();q.pop();
                int v = p.second;
                if (d[v] < p.first) continue;
                for(edge &e:G[v]){
                    if (chmin(d[e.to],d[v]+e.cost)){
                        q.push(P(d[e.to],e.to));
                    }
                }
            }
            return d;
        }
    };
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int k;
    cin >> k;
    Dijkstra g(k);
    rep(i,k){
        g.add_edge(i,(i+1)%k,1);
        g.add_edge(i,10*i%k,0);
    }
    vector<int> d;
    d = g.dijkstra(1);
    PRINT(d[0]+1);
}
