#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

typedef long long ll;

int main() {
    int N, a, b;
    cin >> N;
    vector<vector<int>> edge(N, vector<int>(0));
    rep(i, N - 1) {
        cin >> a >> b;
        a--;
        b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    vector<int> d(N, -1);
    queue<vector<int>> q;
    q.push({0, 0});
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        d[p[0]] = p[1];
        rep(i, edge[p[0]].size()) {
            int j = edge[p[0]][i];
            if (d[j] > -1) continue;
            q.push({j, p[1] + 1});
        }
    }
    int dmax = 0, imax = 0;
    rep(i, N) {
        if (d[i] > dmax) {
            dmax = d[i];
            imax = i;
        }
    }
    rep(i, N) d[i] = -1;
    q.push({imax, 0});
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        d[p[0]] = p[1];
        rep(i, edge[p[0]].size()) {
            int j = edge[p[0]][i];
            if (d[j] > -1) continue;
            q.push({j, p[1] + 1});
        }
    }
    dmax = 0;
    rep(i, N) {
        if (d[i] > dmax) {
            dmax = d[i];
        }
    }
    if (dmax % 3 == 1) cout << "Second" << endl;
    else cout << "First" << endl;
}