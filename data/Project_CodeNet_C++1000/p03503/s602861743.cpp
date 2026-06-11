#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef vector<vector<int>> vv;

// input
int N;
int F[101][10];
int P[101][11];

vector<int> w;


void input() {
    cin >> N;
    rep(i, N) rep(j, 10) cin >> F[i][j];
    rep(i, N) rep(j, 11) cin >> P[i][j];
}


int solve(int x) {
    bitset<10> b(x);
    int ret = 0;
    rep(i, N) {
        int c = 0;
        rep(j, 10) {
            if (F[i][j] == 1 && b.test(j)) c++;
        }
        ret += P[i][c];
    }
    return ret;
}


int main() {
    input();
    int n = pow(2, 10);
    rep(i, n - 1) w.push_back(solve(i + 1));
    int ans = *max_element(w.begin(), w.end());
    cout << ans << endl;
}
