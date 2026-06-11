#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int INF = 101234567;

int main() {
    int N;
    int ans = INF;
    string S;
    cin >> N >> S;

    vector<int>black(N+1);
    vector<int>white(N+1);
    black[0] = 0;
    white[0] = 0;
    int black_cnt = 0;
    int white_cnt = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == '.') {
            white_cnt++;
        } else {
            black_cnt++;
        }
        black[i+1] = black_cnt;
        white[i+1] = white_cnt;
    }

    int total;
    for (int i = 0; i <= N; i++) {
        total = black[i] + white[N] - white[i];
        ans = min(ans, total);
    }

    cout << ans << endl;
}
