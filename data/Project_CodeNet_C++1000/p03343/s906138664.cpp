#include <bits/stdc++.h>
using namespace std;

const int INF = 1000000007;

int main(void){
    int N, K, Q; cin >> N >> K >> Q;
    vector<int> A(N);
    vector<int> cans(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        cans[i] = A[i];
    }
    sort(cans.begin(), cans.end());
    cans.erase(unique(cans.begin(), cans.end()), cans.end());
    
    int ans = INF;
    for (int i = 0; i < cans.size(); i++) {
        int can = cans[i];
        vector<vector<int>> cut;
        vector<int> tmp;
        for (int j = 0; j < N; j++) {
            if (A[j] < can) {
                if (tmp.size()) {
                    cut.push_back(tmp);
                    tmp.clear();
                }
            }
            else tmp.push_back(A[j]);
        }
        if (tmp.size()) cut.push_back(tmp);
        
        vector<int> selected;
        for (int j = 0; j < cut.size(); j++) {
            sort(cut[j].begin(), cut[j].end());
            for (int k = 0; k < (int)cut[j].size() - K + 1; k++) {
                selected.push_back(cut[j][k]);
            }
        }
        sort(selected.begin(), selected.end());
        if (Q <= selected.size()) {
            ans = min(ans, selected[Q-1] - selected[0]);
        }
    }
    
    cout << ans << endl;
}
