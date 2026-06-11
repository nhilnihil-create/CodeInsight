#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

vector<vector<int>> get(vector<int>& A, int X) {
    vector<vector<int>> ret(1, vector<int>());
    for (int& a : A) {
        if (a >= X) {
            ret.back().push_back(a);
        } else if (ret.back().size() > 0) {
            ret.push_back(vector<int>());
        }
    }
    return ret;
}

int main() {
    int N, K, Q;
    cin >> N >> K >> Q;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int ans = 1e9;
    for (int X : A) {
        vector<vector<int>> vs = get(A, X);
        vector<int> cand;
        for (vector<int>& v : vs) {
            sort(v.begin(), v.end());
            int n = v.size();
            for (int i = 0; i < n - K + 1; i++) {
                cand.push_back(v[i]);
            }
        }

        if (cand.size() >= Q) {
            sort(cand.begin(), cand.end());
            ans = min(ans, cand[Q - 1] - X);
        }
    }
    cout << ans << endl;
}
