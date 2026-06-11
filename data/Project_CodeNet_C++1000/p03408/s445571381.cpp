#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;

int main() {
    int N;
    cin >> N;
    vector<string> s(N);
    rep(i, N) cin >> s.at(i);
    int M;
    cin >> M;
    vector<string> t(M);
    rep(i, M) cin >> t.at(i);

    int maxScore = 0;
    rep (i, N) {
        int score = 0;
        rep(j, N) {
            if (s.at(i) == s.at(j)) {
                score++;
            }
        }
        rep(j, M) {
            if (s.at(i) == t.at(j)) {
                score--;
            }
        }
        maxScore = max(maxScore, score);
    }

    cout << maxScore << endl;

    return 0;
}
