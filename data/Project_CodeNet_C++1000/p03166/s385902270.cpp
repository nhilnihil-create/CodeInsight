#include <iostream>
using namespace std;

#define ll long long
#define pb push_back
#define ins insert
#define mp make_pair
#define pii pair<int, int>
#define pil pair<int, ll>
#define pib pair<int, bool>
#define SET(a, c) memset(a, c, sizeof(a))
#define MOD 1000000007
#define enld endl
#define endl "\n"
#define fi first
#define se second
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define FOUND(u, val) u.find(val) != u.end()

#include <string>
#include <vector>
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
//#include <algorithm>
//#include <set>
//#include <map>
//#include <unordered_set>
//#include <unordered_map>
//#include <cmath>
//#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>
vector<vi> adj;
ll longest = 0;
vl distances;
vb visited;
void dfs(int vertex) {
    distances[vertex] = 1;
    for (int n : adj[vertex]) {
        if (!visited[n])
            dfs(n);
        distances[vertex] = max(distances[vertex], distances[n] + 1);
    }
    visited[vertex] = 1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    distances.resize(n + 1);
    visited.resize(n + 1);
    for (int tr = 0; tr < m; tr++) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
    }

    for (int i = 1; i <= n; i++) {
        if (visited[i]) continue;
        dfs(i);
    }
    ll answer = 0;
    for (int i = 1; i <= n; i++) {
        answer = max(distances[i], answer);
    }
    cout << answer - 1;
}
