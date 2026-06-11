#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int N; cin >> N;
    vector<vector<int> > tree(N + 1);
    for (int i = 0; i < N - 1; i++) {
        int a, b; cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    vector<int> cs(N);
    for (int i = 0; i < N; i++) {
        cin >> cs[i];
    }
    sort(cs.begin(), cs.end(), greater<int>());

    vector<pair<int, int> > vande(N + 1);
    int v = 1; 
    int e = tree[1].size();
    for (int i = 1; i <= N; i++) {
        if (e < tree[i].size()) {
            v = i; e = tree[i].size();
        }
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
    vector<int> ans(N + 1);
    vector<bool> added(N + 1, false);
    added[v] = true;
    q.push({e, v});
    int waiwai = - cs[0];
    for (int i = 1; i <= N; i++) {
        int v = q.top().second;
        q.pop();
        ans[v] = cs[i-1];
        waiwai += cs[i-1];
        for (int a:tree[v]) {
            if (!added[a]) {
                added[a] = true;
                q.push({tree[a].size(), a});
            }
        }
    }
    cout << waiwai << endl;
    for (int i = 1; i <= N; i++) {
        printf("%d ", ans[i]);
    }
}