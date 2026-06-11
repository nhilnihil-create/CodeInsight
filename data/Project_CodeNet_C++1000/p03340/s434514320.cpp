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
    
    long long ans = 0, digit = 0;
    int right = 0;
    rep(left, N) {
        while (right < N && digit + A[right] == (digit ^ A[right])) {
            digit += A[right];
            ++right;
        }
        ans += right - left;
        if (left == right) ++right;
        else digit -= A[left];
    }
    cout << ans << endl;
    return 0;
}
