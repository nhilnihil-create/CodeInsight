#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int digit_sum(int x) {
    int res = 0;
    while (x > 0) {
        res += x % 10;
        x /= 10;
    }
    return res;
}

int main() {
    int N;
    cin >> N;
    
    int ans = 1e9;
    REP(A, N) {
        int B = N - A;
        ans = min(ans, digit_sum(A) + digit_sum(B));
    }
    cout << ans << endl;
    return 0;
}
