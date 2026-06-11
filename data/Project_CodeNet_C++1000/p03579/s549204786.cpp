#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

using ll = long long;
const ll MOD = 1e9 + 7;

int main() {
    ll N, M, A, B;
    cin >> N >> M;
    vector<ll> co(N, -1);
    vector<vector<ll>> edge(N, vector<ll>());
    rep(i, M) {
        cin >> A >> B;
        A--;
        B--;
        edge[A].push_back(B);
        edge[B].push_back(A);
    }
    vector<int> c(N, -1);
    co[0] = 0;
    queue<int> q;
    rep(i, edge[0].size()) {
        int j = edge[0][i];
        q.push(j);
        co[j] = 1;
    }
    while (!q.empty()) {
        int i = q.front();
        q.pop();
        rep(j, edge[i].size()) {
            int k = edge[i][j];
            if (co[k] == -1) {
                q.push(k);
                co[k] = 1 - co[i];
                continue;
            }
            if (co[i] != co[k]) continue;
            //rep(i, N) cout << co[i];
            //cout << endl;
            cout << N * (N - 1) / 2 - M << endl;
            return 0;
        }
    }
    ll d[2] = {0, 0};
    rep(i, N) {
        d[co[i]]++;
    }
    //cout << d[0] << " " << d[1] << endl;
    cout << N * (N - 1) / 2 - d[0] * (d[0] - 1) / 2 - d[1] * (d[1] - 1) / 2 - M << endl;
}