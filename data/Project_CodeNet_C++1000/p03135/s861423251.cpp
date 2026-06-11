#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rrep(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back
#define mp make_pair
#define INF9 1000000000 //10^9
#define MOD 1000000007 //10^9+7
#define fi first
#define sc second
using ll=long long;
using pii=pair<ll,ll>;
using vi=vector<int>;

map<int,vi> link;
map<int,int> add;
vi ans;
vector<bool> visited;

void dfs(int v, int a) {
    // printf("v:%d a:%d\n",v,a);
    a += add[v];
    ans[v] += a;
    visited[v] = true;
    for(auto c : link[v]) {
        if(visited[c]) continue;
        dfs(c,a);
    }
}

int main() {
    int t,x; cin >> t >> x;
    cout << (double)(1.0*t/x) << endl;
    return 0;
}
