#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N);
    rep(i, N) cin >> A[i];
    
    rep(i, N) A[i] -= i + 1;
    sort(A.begin(), A.end());
    long long ans = 0;
    rep(i, N) {
        ans += abs(A[N / 2] - A[i]);
    }
    cout << ans << endl;
    return 0;
}
