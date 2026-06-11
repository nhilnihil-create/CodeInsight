#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    int N = 100000;
    vector P(N, true);
    P[0] = P[1] = false;
    int L = (int)sqrt(N);
    for (int i = 2; i <= L; i++) {
        for (int j = i*2; j <= N; j += i) {
            P[j] = false;
        }
    }

    vector<int> WA(N+1, 0);
    for (int i = 1; i <= N; i++) {
        WA[i] = WA[i-1];
        if (P[i] && P[(i + 1) / 2]) WA[i]++;
    }

    int Q; cin >> Q;
    rep(i,Q) {
        int l, r; cin >> l >> r;
        cout << WA[r] - WA[l] + (WA[l] - WA[l-1] == 1) << endl;
    }
}
