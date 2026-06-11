/*
    Author:zeke
    
    pass System Test!
    GET AC!!
*/
#include <iostream>
#include <queue>
#include <vector>
#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>
#include <functional>
#include <cmath>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <map>
#include <iomanip>
#include <utility>
#include <stack>
using ll = long long;
using ld = long double;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rep3(var, min, max) for (ll (var) = (min); (var) < (max); ++(var))
#define repi3(var, min, max) for (ll (var) = (max) - 1; (var) + 1 > (min); --(var))
#define Mp(a,b) make_pair((a),(b))
#define F first
#define S second
#define Icin(s) ll (s);cin>>(s);
#define Scin(s) ll (s);cin>>(s);
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
typedef pair<ll, ll> P;
typedef vector<ll> V;
typedef vector<V> VV;
typedef vector<P> VP;
ll MOD = 1e9 + 7;
ll INF =1e18;
typedef int Weight;
struct Edge {  //src:辺の始点,dst:辺の終点,weight:辺の重さ
  int src, dst;
  Weight weight;
  Edge(int src, int dst, Weight weight) :
    src(src), dst(dst), weight(weight) { }
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;
Graph g;
V vec;
VV have;
bool h=true;
vector<bool> have1;
void dfs(int x,int reg,int prev){
    if(!h)return;
    //cout<<x<<"番目探索開始"<<endl;
    if(vec[x]==1e18){
        vec[x]=reg;
    //    cout<<"更新"<<reg<<endl;
    }else{
        if(reg!=vec[x]){
            h=false;
            return;
        }
    }
    if(have1[x])return;
    have1[x]=true;
    rep(i,g[x].size()){
        if(prev!=g[x][i].dst){
          //  have[i][g[x][i].dst]=1;
            dfs(g[x][i].dst,vec[x]+g[x][i].weight,x);
            if(!h)return;
        }
    }
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,m;
    cin>>n>>m;
    vec.resize(n+1,1e18);
   // have.resize(n+1,V(n+1));
    have1.resize(n+1,false);
    g.resize(n+1);
    rep(i,m){
        ll l,r,d;
        cin>>l>>r>>d;
        g[l].push_back(Edge(l,r,d));
        g[r].push_back(Edge(r,l,-d));
    }
    rep3(i,1,n+1){
        if(vec[i]==1e18){
            dfs(i,0,-1);
        }
    }
    
    if(h){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
}
