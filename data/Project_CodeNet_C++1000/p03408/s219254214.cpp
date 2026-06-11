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

    set<string> uniqS;
    rep(i, N) {
        uniqS.insert(s.at(i));
    }

    int maxScore = 0;
    for (string target : uniqS) {
        int score = 0;
        rep(i, N) {
            if (target == s.at(i)) {
                score++;
            }
        }
        rep(i, M) {
            if (target == t.at(i)) {
                score--;
            }
        }
        maxScore = max(maxScore, score);
    }

    cout << maxScore << endl;

    return 0;
}
