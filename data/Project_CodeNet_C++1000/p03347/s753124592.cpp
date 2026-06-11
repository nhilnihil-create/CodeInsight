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
    
    bool judge = true;
    rep(i, N) {
        if (A[i] > i) judge = false;
    }
    REP(i, N) {
        if (A[i] > A[i - 1] + 1) judge = false;
    }
    if (!judge) {
        cout << -1 << endl;
        return 0;
    }
    
    long long ans = 0;
    REP(i, N) {
        if (A[i - 1] + 1 != A[i]) ans += A[i - 1];
    }
    ans += A[N - 1];
    cout << ans << endl;
    return 0;
}
