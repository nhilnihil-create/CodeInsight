#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

using ll = long long;

int main() {
    int N, K, Q, ans = 1e9;
    cin >> N >> K >> Q;
    vector<int> A(N), B(N);
    set<int> s = {-1, N};
    map<int, int> m;
    rep(i, N) {
        cin >> A[i];
        B[i] = A[i];
        m[A[i]] = i;
    }
    sort(B.begin(), B.end());
    rep(i, N - K + 1) {
        auto j = s.begin();
        int l = *j + 1;
        vector<int> v;
        rep(k, s.size() - 1) {
            j++;
            int r = *j;
            if (r - l >= K) {
                vector<int> w;
                for (int p = l; p < r; p++) {
                    w.push_back(A[p]);
                }
                sort(w.begin(), w.end());
                rep(p, r - l - K + 1) v.push_back(w[p]);
            }
            l = r + 1;
        }
        if (v.size() < Q) break;
        sort(v.begin(), v.end());
        ans = min(ans, v[Q - 1] - v[0]);
        s.insert(m[B[i]]);
    }
    cout << ans << "\n";
}