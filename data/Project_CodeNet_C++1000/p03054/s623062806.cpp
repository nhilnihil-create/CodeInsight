#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i<(n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
using ll = long long;

int H, W, N, sr, sc;
string S, T;

bool solve() {
    // left, right
    int left = 0, right = W;
    if (S[N - 1] == 'L') ++left;
    if (S[N - 1] == 'R') --right;
    for (int i = N - 2; i >= 0; --i) {
        if (T[i] == 'L') right = min(right + 1, W);
        else if (T[i] == 'R') left = max(0, left - 1);
        if (S[i] == 'L') left = left + 1;
        else if (S[i] == 'R') right = right - 1;
        if (left >= right) return false;
    }
    if (sc < left || sc >= right) return false;

    // up, down
    left = 0, right = H;
    if (S[N - 1] == 'U') ++left;
    if (S[N - 1] == 'D') --right;
    for (int i = N - 2; i >= 0; --i) {
        if (T[i] == 'U') right = min(right + 1, H);
        else if (T[i] == 'D') left = max(0, left - 1);
        if (S[i] == 'U') left = left + 1;
        else if (S[i] == 'D') right = right - 1;
        if (left >= right) return false;
    }
    if (sr < left || sr >= right) return false;

    return true;
}

int main() {
    cin >> H >> W >> N >> sr >> sc >> S >> T;
    sr--;
    sc--;
    if (solve()) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}