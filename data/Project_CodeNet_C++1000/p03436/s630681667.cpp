#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef vector<vector<int>> vv;
typedef pair<int, int> P;

// input
int H, W;
vector<string> S;

vector<int> w;
vector<bool> l;


void input() {
    cin >> H >> W;
    S = vector<string>(H);
    rep(i, H) cin >> S[i];
}


int to_id(int x, int y) {
    return W * x + y;
}


void solve() {
    w = vector<int>(H * W, -1);
    l = vector<bool>(H * W, false);
    w[0] = 1;
    l[0] = true;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        int x = v / W;
        int y = v % W;
        if (x > 0) {
            int i = to_id(x - 1, y);
            if (S[x - 1][y] == '.' && !l[i]) {
                w[i] = w[v] + 1;
                l[i] = true;
                q.push(i);
            }
        }
        if (x < H - 1) {
            int i = to_id(x + 1, y);
            if (S[x + 1][y] == '.' && !l[i]) {
                w[i] = w[v] + 1;
                l[i] = true;
                q.push(i);
            }
        }
        if (y > 0) {
            int i = to_id(x, y - 1);
            if (S[x][y - 1] == '.' && !l[i]) {
                w[i] = w[v] + 1;
                l[i] = true;
                q.push(i);
            }
        }
        if (y < W - 1) {
            int i = to_id(x, y + 1);
            if (S[x][y + 1] == '.' && !l[i]) {
                w[i] = w[v] + 1;
                l[i] = true;
                q.push(i);
            }
        }
    }
}


int main() {
    input();
    solve();
    int s = 0;
    rep(i, H) s += count(S[i].begin(), S[i].end(), '.');
    int ans;
    if (w[H * W - 1] == -1) ans = -1;
    else ans = s - w[H * W - 1];
    cout << ans << endl;
}
