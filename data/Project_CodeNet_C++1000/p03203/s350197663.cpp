#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int H, W, N;
    cin >> H >> W >> N;
    vector<int> x(N), y(N), idxs(N), memo(H, W);
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
        x[i]--;
        y[i]--;
        memo[x[i]] = min(memo[x[i]], y[i]);
        idxs[i] = i;
    }
    
    int ans = H;
    int cy = 0;
    for (int i = 1; i < H; i++) {
        if (memo[i] <= cy) {
            ans = i;
            break;
        } else if (memo[i] != cy + 1) {
            cy++;
        }
    }
    cout << ans << endl;
    return 0;
}