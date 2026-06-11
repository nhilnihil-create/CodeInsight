#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

typedef long long ll;

int main() {
    ll N, A, B;
    cin >> N >> A >> B;
    if (N < A + B - 1 || N > A * B) {
        cout << "-1\n";
        return 0;
    }
    if (B == 1) {
        rep(i, N) {
            cout << i + 1;
            if (i == N - 1) cout << "\n";
            else cout << " ";
        }
        return 0;
    }
    ll q = (N - A - B + 1) / (B - 1);
    ll r = (N - A - B + 1) % (B - 1);
    vector<int> ans;
    rep(i, q + 1) {
        rep(j, B) {
            ans.push_back((i + 1) * B - j);
        }
    }
    int s = (q + 1) * B;
    if (r > 0) {
        rep(i, r + 1) {
            ans.push_back((q + 1) * B + r + 1 - i);
        }
        s += r + 1;
    }
    if (s < N) {
        for (int i = s + 1; i <= N; i++) ans.push_back(i);
    }
    rep(i, ans.size()) {
        cout << ans[i];
        if (i == ans.size() - 1) cout << "\n";
        else cout << " ";
    }
}