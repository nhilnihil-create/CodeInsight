#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    int A[N];
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        A[i] -= (i + 1);
    }
    sort(A, A + N);

    long long b = A[N/2];
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        long long tmp = A[i] - b;
        ans += max(-1 * tmp, tmp);
    }
    cout << ans << endl;
}