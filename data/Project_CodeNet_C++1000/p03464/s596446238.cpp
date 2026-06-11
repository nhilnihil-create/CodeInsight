#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int K;
vector<long long> A(100000);

long long winner(long long n) {
    if (n == 0) return 0;
    rep(i, K) {
        n = n / A[i] * A[i];
    }
    return n;
}

int main() {
    cin >> K;
    rep(i, K) cin >> A[i];
    
    long long left = 0;
    long long right = 1e15;
    while (right - left > 1) {
        long long mid = (right + left) / 2;
        if (winner(mid) < 2) left = mid;
        else right = mid;
    }
    if (winner(right) != 2) {
        cout << -1 << endl;
        return 0;
    }
    cout << right << " ";
    left = 0;
    right = 1e15;
    while (right - left > 1) {
        long long mid = (right + left) / 2;
        if (winner(mid) > 2) right = mid;
        else left = mid;
    }
    cout << left << endl;
    return 0;
}
