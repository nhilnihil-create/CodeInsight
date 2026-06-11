#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int N, S = 0;
    cin >> N;
    vector<int> A(N + 2, 0);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        S += abs(A[i] - A[i - 1]);
    }
    S += abs(A[N + 1] - A[N]);
    for (int i = 1; i <= N; i++) {
        cout << S - abs(A[i - 1] - A[i]) - abs(A[i] - A[i + 1]) + abs(A[i - 1] - A[i + 1]) << endl;
    }
}
