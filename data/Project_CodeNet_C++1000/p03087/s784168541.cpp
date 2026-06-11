#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define Rep(i, n) for (int i = 0; i < (int)(n); i++)
#define BitRep(i, n) for (int i = 0; i < (int)(1 << n); i++)
#define All(vec) vec.begin(), vec.end()
#define Sum(vec) accumulate(vec.begin(), vec.end(), 0)
#define Sort(vec) sort(vec.begin(), vec.end())
#define Reverse(vec) reverse(vec.begin(), vec.end())
#define Next_permutation(vec) next_permutation(vec.begin(), vec.end())
#define PI acos(-1)

int main() {
    int N, Q;
    string S;
    cin >> N >> Q >> S;
    vector<int> dp(N + 1);
    int cnt = 0;
    Rep(i, N) {
        if (i) {
            if (S[i - 1] == 'A' && S[i] == 'C') cnt++;
        }
        dp[i + 1] = cnt;
    }
    Rep(i, Q) {
        int l, r;
        cin >> l >> r;
        cout << dp[r] - dp[l] << endl;
    }
    return 0;
}