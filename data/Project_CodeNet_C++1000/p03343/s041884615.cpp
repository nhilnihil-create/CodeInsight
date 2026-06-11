#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, K, Q;
    cin >> N >> K >> Q;

    vector<int> A(N);
    for (int i=0; i < N; ++i) cin >> A[i];

    int ans = INT_MAX;
    for (int i=0; i<(int)A.size(); ++i) {
        int x = A[i];
        vector<int> v, cand;
        for (int j=0; j<N; ++j) {
            if (A[j] < x) {
                sort(v.begin(), v.end());
                for (int k=0; k+K-1<(int)v.size(); ++k) {
                    cand.push_back(v[k]);
                }
                v.clear();
            } else {
                v.push_back(A[j]);
            }
        }
        if ( ! v.empty()) {
            sort(v.begin(), v.end());
            for (int k=0; k+K-1<(int)v.size(); ++k) {
                cand.push_back(v[k]);
            }
        }
        
        if (cand.size() < Q) continue;
        
        sort(cand.begin(), cand.end());
        ans = min(ans, cand[Q-1] - x);
    }

    cout << ans << endl;

    return 0;
}