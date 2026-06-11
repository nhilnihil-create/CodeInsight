#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>

using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define reps(i, f, n) for (int i = (f); i < (n); i++)
ll const INF = 1LL << 60;

int main() {
    int N, M, C;
    cin >> N >> M >> C;

    int B[M];
    rep(i, M) cin >> B[i];

    int A[N][M];
    rep(i, N) rep(j, M) cin >> A[i][j];

    int ans = 0;
    for (int i = 0; i < N; i++) {
        int sum = 0;

        for (int j = 0; j < M; j++) {
            sum += A[i][j] * B[j];
        }
        sum += C;
        if (sum > 0)
            ans++;

    }
    cout << ans << endl;

   return 0;
}