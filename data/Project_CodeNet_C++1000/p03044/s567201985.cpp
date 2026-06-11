#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for (int i=0; i< (int)(n); i++)
typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<int> V(N, -1);
    vector<vector<int>> to(N), cost(N);
    int ui, vi, wi;
    rep(i,N-1) {
        cin >> ui >> vi >> wi;
        ui--;
        vi--;
        wi %= 2;
        to[ui].push_back(vi);
        to[vi].push_back(ui);
        cost[ui].push_back(wi);
        cost[vi].push_back(wi);
    }
    queue<int> q;
    V[0] = 0;
    q.push(0);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        rep(i, to[v].size()) {
            int u = to[v][i];
            int w = cost[v][i];
            if (V[u] != -1) continue;
            V[u] = (V[v] + w) % 2;
            q.push(u);
        }
    }

    rep(i,N) {
        cout << V[i] << endl;
    }
}