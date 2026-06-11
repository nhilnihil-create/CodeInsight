#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef pair<int, int> pii;
// #define INF __INT32_MAX__
#define INF 1e9
#define LINF __LONG_LONG_MAX__

int main() {
    int N; cin >> N;
    vi A(N); rep(i, N) cin >> A[i];

    int res = -1;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            res = max(res, abs(A[i] - A[j]));
        }
    }

    cout << res << endl;
}
