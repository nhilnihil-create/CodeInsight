#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int N;
    cin >> N;
    vector<int> V(N), C(N);
    rep(i, N) cin >> V[i];
    rep(i, N) cin >> C[i];
    int ans = 0;
    for (int bit = 0; bit < (1 << N); ++bit) {
        int price = 0;
        int cost = 0;
        for (int i = 0; i < N; ++i) {
            if (bit & (1 << i)) {
                price += V[i];
                cost += C[i];
            }
        }
        ans = max(ans, price - cost);
    }
    cout << ans << endl;
}