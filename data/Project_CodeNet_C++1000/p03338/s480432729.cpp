#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

typedef long long ll;

int main() {
    int N, ans = 0;
    string S;
    cin >> N >> S;
    for (int i = 1; i < N; i++) {
        vector<bool> a(26, false), b(26, false);
        rep(j, i) {
            a[S[j] - 'a'] = true;
        }
        rep(j, N - i) {
            b[S[j + i] - 'a'] = true;
        }
        int c = 0;
        rep(j, 26) {
            if (a[j] && b[j]) c++;
        }
        ans = max(ans, c);
    }
    cout << ans << "\n";
}