#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
using Tree = vector<vector<int>>;

int N;
vector<long long> D;
map<long long, int> dtoi;
vector<int> subtree_size;

long long rec(const Tree &G, int v) {
    long long res = 0;
    for (auto c : G[v]) {
        res += rec(G, c) + subtree_size[c];
    }
    return res;
}

void solve() {
    subtree_size.assign(N, 1);
    vector<int> par(N, -1);
    Tree G(N);

    // greedy from leaves
    sort(D.begin(), D.end(), greater<long long>());
    for (int i = 0; i < N-1; ++i) {
        int id = dtoi[D[i]];
        int s = subtree_size[id];
        long long l = N - s * 2;
        long long nextD = D[i] - l;


        //cout << D[i] << ", " << id << ": " << s << ", " << l << ", " << nextD << endl;
        
        if (!dtoi.count(nextD)) {
            cout << -1 << endl;
            return;
        }
        int nid = dtoi[nextD];
        par[id] = nid;
        subtree_size[nid] += subtree_size[id];
        G[nid].push_back(id);
    }

    // final check
    long long DD = rec(G, dtoi[D.back()]);
    if (DD != D.back()) {
        cout << -1 << endl;
        return;
    }

    // output
    for (int i = 0; i < N; ++i) {
        if (par[i] == -1) continue;
        cout << i+1 << " " << par[i]+1 << endl;
    }
}

int main() {
    cin >> N;
    D.resize(N);
    for (int i = 0; i < N; ++i) cin >> D[i], dtoi[D[i]] = i;
    solve();
}
    
