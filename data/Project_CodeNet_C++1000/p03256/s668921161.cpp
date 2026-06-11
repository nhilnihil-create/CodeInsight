
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <sstream>
#include <string>
#define _repargs(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rep(...) _repargs(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()
#define mod 1000000007
#define inf 2000000007
#define mp make_pair
#define pb push_back
typedef long long ll;
using namespace std;
template <typename T>
inline void output(T a, int p = 0) {
    if(p) cout << fixed << setprecision(p)  << a << "\n";
    else cout << a << "\n";
}
// end of template

vector<vector<int>> G;
vector<int> vis;
vector<int> ts;

bool loop = false;
void dfs(int cur) {
    if(vis[cur] == 1) {
        loop = true;
        return;
    }
    else if(vis[cur] == 0){
        vis[cur] = 1;
        for(int v: G[cur]) {
            dfs(v);
        }
        vis[cur] = 2;
        ts.pb(cur);
    }
}

template <typename T> inline void voutput(T &v){
    rep(i, v.size()){
        if (i) cout << " " << v[i];
        else cout << v[i];
    }
    cout << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    // source code
    int N, M;
    cin >> N >> M;
    string s;
    cin >> s;
    G.resize(2 * N);
    
    // AABB
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        if(s[a] == 'A' && s[b] == 'A') {
            G[a].pb(b + N);
            if(a != b) G[b].pb(a + N);
        }
        if(s[a] == 'A' && s[b]  == 'B') {
            G[a + N].pb(b);
            G[b + N].pb(a);
        }
        if(s[a] == 'B' && s[b] == 'A') {
            G[a + N].pb(b);
            G[b + N].pb(a);
        }
        if(s[a] == 'B' && s[b] == 'B') {
            G[a].pb(b + N);
            if(a != b) G[b].pb(a + N);
        }
    }
    
    vis.assign(2 * N, 0);
    
    rep(i, 2 * N) {
        if(vis[i] == 0) {
            dfs(i);
        }
    }
    reverse(all(ts));
    
    if(loop) {
        output("Yes");
    }
    else {
        output("No");
    }
    
    return 0;
}
