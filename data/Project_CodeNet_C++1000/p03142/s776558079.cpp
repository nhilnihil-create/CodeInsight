#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <bitset>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <utility>
#include <set>
#include <map>
#include <tuple> 
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
using namespace  std;
typedef pair<long long , long long> P;
typedef long long ll;
typedef long long lint;
#define REP(i, n) for(long long (i)=0; (i)<(n); ++i)
#define FOR(i, a, b) for(long long (i)=(a); (i)<(b); ++i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
const long long MOD = static_cast<long long>(1e9) + 7LL;
const long long INF = 1234567891234567890LL;
vector<vector<ll>> G;
vector<vector<ll>> H;
vector<ll> topo;
vector<int> visited;
void topologicalSort(ll v){
    visited[v] = 1;
    for(ll i=0; i<G[v].size(); i++){
        ll nv = G[v][i];
        if(!visited[nv]) topologicalSort(nv);
    }
    topo.push_back(v);
}
signed main(){
    ll N, M;
    cin >> N>>M;
    G.resize(N);
    H.resize(N);
    visited.resize(N, 0);
    for(long long i=0; i<N-1+M; i++){
        ll a, b; cin >> a >> b;
        G[--a].push_back(--b);
        H[b].push_back(a);
    }
    ll root=-1;
    REP(i, N) if(H[i].size()==0) root = i;
    topologicalSort(root);
    reverse(ALL(topo));
    vector<ll> cmp(N);
    REP(i, N){
        cmp[topo[i]] = i;
    } 
    vector<ll> res(N);
    REP(i, N){
        if((int)H[i].size()==1) res[i] = H[i][0]+1;
        else if(H[i].size()==0) res[i] = 0;
        else{
            ll pid = -1;
            for(ll j=0; j<H[i].size(); j++){
                if(pid< cmp[H[i][j]]){
                    pid = cmp[H[i][j]];
                    res[i] = H[i][j]+1;
                } 
            }
        }
    }
    REP(i, N) cout << res[i] << endl;
    return 0;
}