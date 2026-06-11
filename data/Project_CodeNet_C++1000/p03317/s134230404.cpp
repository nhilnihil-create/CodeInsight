#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
const int MOD = 1000000009;
const long long INF = 1LL << 60;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    int res = 0;
    if (K == N) res = 1;
    else if (K == 2) res = N - 1;
    else for (int i = 0; i < N - 1; i += K-1) ++res;
    cout << res << endl;
    return 0;
}