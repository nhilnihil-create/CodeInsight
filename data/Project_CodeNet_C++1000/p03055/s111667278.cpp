#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<deque>
#include<cmath>
#include<map>
#include<unordered_map>
#include<set>
#include<cstring>
#include<iomanip> //cout << fixed << setprecision(15) << x << endl;

using namespace std;
typedef long long ll;
const ll INF = 1e9 + 8;
const ll MOD = 1e9 + 7;
const ll LLINF = 1e18;
#define Pint pair<int, int>
#define Graph vector<vector<int>>
#define rng(i, a, b) for(ll i = ll(a); i < ll(b); i++)
#define rnr(i, a, b) for(ll i = ll(a); i >= ll(b); i--)
#define rep(i, b) rng(i, 0, b)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
/* -- template -- */

int maxv = 0;
int maxv_i = 0;
Graph tree;

void dfs(int from, int now, int dist) {
    for(int next : tree[now]) {
        if(next == from) continue;
        dfs(now, next, dist + 1);
    }
    if(dist > maxv) maxv_i = now, maxv = dist;
    return;
}

int main() {
    int n; cin >> n;
    int a[n - 1], b[n - 1];
    tree.resize(n);
    rep(i, n - 1) {
        cin >> a[i] >> b[i]; --a[i], --b[i];
        tree[a[i]].pb(b[i]); tree[b[i]].pb(a[i]);
    }
    dfs(0, 0, 0);
    dfs(maxv_i, maxv_i, 0);
    cout << (((maxv - 1) % 3 == 0) ? "Second" : "First") << endl;
}
