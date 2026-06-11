#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef vector<vector<int>> vv;
typedef pair<int, int> P;

// input
int H, W;
vector<string> S;

char s[52][52];
int w[50][50];


void input() {
    cin >> H >> W;
    S = vector<string>(H);
    rep(i, H) cin >> S[i];
}


int solve(int i, int j) {
    int ret = 0;
    rep(a, 3) rep(b, 3) {
        if (a == 1 && b == 1) continue;
        if (s[i + a - 1][j + b - 1] == '#') ret++;
    }
    return ret;
}


int main() {
    input();
    rep(i, 52) rep(j, 52) s[i][j] = '.';
    rep(i, H) rep(j, W) s[i + 1][j + 1] = S[i][j];
    rep(i, H) rep(j, W) {
        if (s[i + 1][j + 1] == '.') w[i][j] = solve(i + 1, j + 1);
    }
    rep(i, H) {
        rep(j, W) {
            if (S[i][j] == '#') cout << '#';
            else cout << w[i][j];
        }
        cout << endl;
    }
}
