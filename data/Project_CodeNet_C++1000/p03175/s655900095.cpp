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
#define max_self(a, b) a = max(a, b);

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
vl black, white;
void dfs(int a, int parent = 0) {
    if (adj[a].size() == 1 && a != 1) return;
    for (int b : adj[a]) {
        if (b != parent) {
            dfs(b, a);
        }
    }
    ll p1 = 1;
    ll p2 = 1;
    for (int child : adj[a]) {
        if (child == parent) continue;
        p1 = (p1 * (white[child] + black[child])) % MOD;
        p2 = (p2 * white[child]) % MOD;
    }
    white[a] = p1, black[a] = p2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    adj.resize(n + 1);
    black.resize(n + 1);
    white.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for (int i = 2; i <= n; i++) {
        if (adj[i].size() == 1) {
            black[i] = 1;
            white[i] = 1;
        }
    }
    dfs(1);
    // for (int i = 1; i <= n; i++) {
    //     cout << white[i] << " " << black[i] << endl;
    // }
    cout << ((white[1] + black[1]) % MOD);
}