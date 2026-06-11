#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<string> b(N);
    for (int i = 0; i < N; i++) {
        cin >> b[i];
    }
    int M;
    cin >> M;
    vector<string> r(M);
    for (int i = 0; i < M; i++) {
        cin >> r[i];
    }
    int ans = 0;
    for (string s : b) {
        int score = 0;
        for (string sb : b) {
            if (s == sb) score++;
        }
        for (string sr : r) {
            if (s == sr) score--;
        }
        ans = max(score, ans);
    }
    cout << ans << endl;
}
