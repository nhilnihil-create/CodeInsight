#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define MOD 1000000007
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef pair<int, int> P;
typedef pair<long long, long long> LLP;

int main() {

    int N, M;
    cin >> N >> M;
    vector<int> A(M);
    int match[10] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    rep(i,M) cin >> A[i];

    sort(A.begin(), A.end(), greater<int>());

    int dp[N + 1];
    rep(i,N+1) dp[i] = -MOD;
    dp[0] = 0;
    for (int i = 1; i <= N; i++) {
        rep(j,M) {
            if (i - match[A[j]] >= 0) {
                dp[i] = max(dp[i], dp[i - match[A[j]]] + 1);
            }
        }
    }

    int count = N;

    rep(i,dp[N]) {
        rep(j,M) {
            if ((dp[count] == 1 && match[A[j]] == count) || (dp[count] != 1 && count - match[A[j]] >= 0 && dp[count - match[A[j]]] + 1 == dp[count])) {
                count -= match[A[j]];
                cout << A[j];
                break;
            }
        }
    }
    cout << endl;

    return 0;
}