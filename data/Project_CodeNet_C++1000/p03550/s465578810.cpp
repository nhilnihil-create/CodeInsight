#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<bool> vb;
typedef vector<char> vc;
#define INF __INT32_MAX__
#define LINF __LONG_LONG_MAX__

int main() {
    int N, Z, W; cin >> N >> Z >> W;
    vi A(N); rep(i, N) cin >> A[i];

    int res = 0;

    res = max(res, abs(A[N - 1] - W));
    if (N > 1) res = max(res, abs(A[N - 1] - A[N - 2]));

    cout << res << endl;
}
