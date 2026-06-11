#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<int> P(m), Y(m);
    for (int i = 0; i < m; ++i) cin >> P[i] >> Y[i], --P[i];
    
    vector<vector<int> > vals(n);
    for (int i = 0; i < m; ++i) vals[P[i]].push_back(Y[i]);
    
    for (int v = 0; v < n; ++v) {
        sort(vals[v].begin(), vals[v].end());
        
        vals[v].erase(unique(vals[v].begin(), vals[v].end()), vals[v].end());
    }

    for (int i = 0; i < m; ++i) {
        int v = P[i];
        printf("%06d", v + 1);
        
        int id = lower_bound(vals[v].begin(), vals[v].end(), Y[i]) - vals[v].begin();
        printf("%06d\n", id + 1);
    }
}
