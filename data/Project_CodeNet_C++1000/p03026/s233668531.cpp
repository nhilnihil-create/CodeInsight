#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
const ll mod = 1000000007;
const int MAX_N = 10010;

int main() {
    int n;
    cin >> n;

    Graph G(n);
    rep(i, n-1) {
        int a, b;
        cin >> a >> b;
        a--;  b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    queue<int> Q;

    vector<int> c(n);
    vector<int> deg(n);
    rep(i, n) {
        cin >> c[i];
        deg[i] = G[i].size();
        if(G[i].size() == 1) {
            Q.push(i);
        }
    }

    sort(c.begin(), c.end());

    vector<int> d(n);
    int M = 0;    
    rep(i, n) {

        int v = Q.front();
        Q.pop();

        d[v] = c[i];

        if(i < n-1) {
            M += c[i];
        }

        rep(j, G[v].size()) {
            int to = G[v][j];
            deg[to]--;
            if(deg[to] == 1) {
                Q.push(to);
            }
        }
    }

    cout << M << "\n";

    rep(i, n) {
        cout << d[i] << " ";
    }

    cout << endl;
    return 0;
}