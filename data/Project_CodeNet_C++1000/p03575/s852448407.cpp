#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef vector<vector<int>> vv;
typedef pair<int, int> P;

// input
int N, M;
vector<int> A, B;

const int INF = 1e9;
int w[50][50];


void input() {
    cin >> N >> M;
    A = B = vector<int>(M);
    rep(i, M) {
        cin >> A[i] >> B[i];
        A[i]--;
        B[i]--;
    }
}


bool judge() {
    int v[50][50];
    rep(i, 50) rep(j, 50) v[i][j] = w[i][j];
    rep(k, N) rep(i, N) rep(j, N) {
        v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
    }
    rep(i, N) rep(j, N) if (v[i][j] == INF) return true;
    return false;
}


int main() {
    input();
    rep(i, N) rep(j, N) {
        if (i == j) w[i][j] = 0;
        else w[i][j] = INF;
    }
    rep(i, M) w[A[i]][B[i]] = w[B[i]][A[i]] = 1;
    
    int ans = 0;
    rep(i, M) {
        w[A[i]][B[i]] = w[B[i]][A[i]] = INF;
        if (judge()) ans++;
        w[A[i]][B[i]] = w[B[i]][A[i]] = 1;
    }
    cout << ans << endl;
}
