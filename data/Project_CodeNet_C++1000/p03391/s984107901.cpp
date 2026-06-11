#include <iostream>
#include <vector>
using namespace std;

int N;
vector<long long> A, B;

long long solve() {
    if (A == B) return 0;
    long long sum = 0, mi = 1LL<<60;
    for (int i = 0; i < N; ++i) {
        sum += A[i];
        if (A[i] > B[i]) mi = min(mi, B[i]);
    }
    return sum - mi;
}

int main() {
    cin >> N;
    A.resize(N), B.resize(N);
    for (int i = 0; i < N; ++i) cin >> A[i] >> B[i];
    cout << solve() << endl;
}
