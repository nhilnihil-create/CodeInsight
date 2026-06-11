#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    vector<int> white(N + 1);
    rep(i, N) {
        white[i + 1] = white[i];
        if (S[i] == '.') ++white[i + 1];
    }

    int ans = N;
    rep(i, N) {
        int tmp = (i + 1 - white[i + 1]) + (white[N] - white[i + 1]);
        ans = min(ans, tmp);
    }

    cout << min({ans, white[N], N - white[N]}) << endl;
}