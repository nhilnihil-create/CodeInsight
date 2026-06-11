#include <iostream>
#include <vector>
using namespace std;
long long GCD(long long a, long long b) { return b ? GCD(b, a%b) : a; }

int main() {
    int N; cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];

    long long res = A[0];
    for (int i = 0; i < N; ++i) {
        res = GCD(res, A[i]);
    }
    cout << res << endl;
}