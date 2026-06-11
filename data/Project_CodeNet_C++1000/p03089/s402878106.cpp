#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    int N; cin >> N;
    vector<int> B(N);
    rep(i,N) {
        int b; cin >> b; b--;
        B[i] = b;
    }
    vector<int> C;
    while (!B.empty()) {
        int cnt = 0, ma = 0;
        for (int i = 0; i < B.size(); i++) {
            if (i == B[i]) {
                cnt++;
                ma = i;
            }
        }
        if (cnt == 0 && !B.empty()) {
            cout << -1 << endl;
            return 0;
        } else {
            B.erase(B.begin() + ma);
            C.push_back(ma);
        }
    }
    reverse(C.begin(), C.end());
    rep(i,N) cout << C[i]+1 << endl;
}