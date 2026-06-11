#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1001001001
#define LINF 1001001001001001001
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define bit(n) (1LL<<(n))
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> LLP;

void rec(int v, vector<vector<int>> &edges, vector<bool> &visited, vector<int> &order) {
    visited[v] = true;
    for (int u : edges[v]) {
        if (visited[u]) continue;
        rec(u, edges, visited, order);
    }
    order.push_back(v);
}

int main() {

    int N, M;
    cin >> N >> M;
    vector<int> count_dest(N, 0);
    vector<vector<int>> edges(N), edges_rev(N);

    rep(i,N-1+M) {
        int A, B;
        cin >> A >> B;
        A--; B--;
        count_dest[B]++;
        edges[A].push_back(B);
        edges_rev[B].push_back(A);
    }

    int root = -1;
    rep(i,N) if (count_dest[i] == 0) root = i;

    vector<int> order;
    vector<bool> visited(N, false);

    rec(root, edges, visited, order);
    reverse(order.begin(), order.end());

    vector<int> order_c(N);
    rep(i,N) order_c[order[i]] = i;
    
    rep(i,N) {
        if (i == root) {
            cout << 0 << endl;
            continue;
        }
        int nearest = edges_rev[i][0];
        for (int v : edges_rev[i]) {
            if (order_c[v] > order_c[nearest]) nearest = v;
        }

        cout << nearest + 1 << endl;
    }

    return 0;
}