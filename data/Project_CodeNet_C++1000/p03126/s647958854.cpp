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
    int N, M;
    cin >> N >> M;
    
    int A[N][30];
    int K[N];

    for (int i = 0; i < N; i++) {
        cin >> K[i];
        rep(j, K[i]) cin >> A[i][j];
    }

    int cnt[M];
    for (int i = 0; i < M; i++)
        cnt[i] = 0;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K[i]; j++) {
            cnt[A[i][j]-1]++;
        }
    }

    int ans = 0;
    for (int i = 0; i < M; i++) {
        if (cnt[i] == N)
            ans++;
    }
    cout << ans << endl;

    return 0;
}