#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;

void solve() {
    int N; cin >> N;
    vector<int> B(N);
    for(auto &e : B) cin >> e;
    vector<int> A;
    while(!B.empty()) {
        for(int i = B.size() - 1; i >= 0; --i) {
            if(B[i] > i + 1) {
                cout << -1 << '\n';
                return;
            }
            if(B[i] == i + 1) {
                B.erase(B.begin() + i);
                A.push_back(i + 1);
                break;
            }
        }
    }
    reverse(A.begin(), A.end());
    rep(i, N) cout << A[i] << '\n';
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}
