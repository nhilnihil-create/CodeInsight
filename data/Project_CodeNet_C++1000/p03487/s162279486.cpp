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
    int N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    std::array<int, 100010> check{};
    int res = 0;
    for (int i = 0; i < N; ++i) {
        if (A[i] < 100010) ++check[A[i]];
        else ++res;
    }
    for (int i = 0; i < check.size(); ++i) {
        if (check[i] == 0) continue;
        if (check[i] == i) continue;
        if (check[i] > i) res += check[i] - i;
        else res += check[i];
        
    }
    cout << res << endl;
    return 0;
}