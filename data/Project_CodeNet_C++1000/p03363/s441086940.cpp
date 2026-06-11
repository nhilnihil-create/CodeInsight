#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    
    vector<long long> S(N + 1, 0);
    rep(i, N) S[i + 1] = S[i] + A[i];
    sort(S.begin(), S.end());
    long long ans = 0;
    rep(i, N + 1) {
        auto iter0 = lower_bound(S.begin(), S.begin() + i, S[i]);
        auto iter1 = upper_bound(S.begin(), S.begin() + i, S[i]);
        ans += distance(iter0, iter1);
    }
    cout << ans << endl;
    return 0;
}
