#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef vector<vector<int>> vv;
typedef pair<int, int> P;

// input
int N, M, C;
vector<int> B;
int A[21][21];


void input() {
    cin >> N >> M >> C;
    B = vector<int>(M);
    rep(i, M) cin >> B[i];
    rep(i, N) rep(j, M) cin >> A[i][j];
}


int main() {
    input();
    int ans = 0;
    rep(i, N) {
        int s = C;
        rep(j, M) s += A[i][j] * B[j];
        if (s > 0) ans++;
    }
    cout << ans << endl;
}
