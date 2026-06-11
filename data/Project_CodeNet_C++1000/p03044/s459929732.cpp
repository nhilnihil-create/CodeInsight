#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<ll,ll,ll> T;
const long long INF = 1LL<<60;
const int MOD = 1000000000+7;
#define rev(s) (string((s).rbegin(), (s).rend()))
template < typename T > inline string toString( const T &a ) { ostringstream oss; oss << a; return oss.str(); };
// cout << fixed << setprecision(10) << ans << endl;
// *min_element(c + l, c + r) *max_element(c + l, c + r)
// int dx[8]={1,1,0,-1,-1,-1,0,1};
// int dy[8]={0,1,1,1,0,-1,-1,-1};
// int dx[4]={1,0,-1,0};
// int dy[4]={0,1,0,-1};
// struct Edge {
//   int to, id;
//   Edge(int to, int id): to(to), id(id) {}
// };

int main() {
    int N;cin>>N;
    vector<vector<P>> tree(N,vector<P>());
    rep(i,N-1) {
        int u,v,w;cin>>u>>v>>w;
        u--;v--;
        w = w % 2;
        tree[u].push_back(P(v,w));
        tree[v].push_back(P(u,w));
    }
    vector<int> color(N,-1);
    color[0] = 0;
    queue<int> qu;
    qu.push(0);
    while(!qu.empty()) {
        int now = qu.front();
        qu.pop();
        for(auto nxt : tree[now]) {
            if(color[nxt.first]==-1) {
                if(nxt.second){
                    color[nxt.first] = 1 - color[now];
                } else {
                    color[nxt.first] = color[now];
                }
                qu.push(nxt.first);
            }
        }
    }
    rep(i,N) cout<<color[i]<<endl; 
}