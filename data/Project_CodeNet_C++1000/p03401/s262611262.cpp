#include "bits/stdc++.h"
 
using namespace std;
 
void Main() {
    int N;
    cin >> N;
    vector<int> A(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
 
    int total = abs(0 - A[0]);
    for (int i = 1; i < N; ++i) {
        total += abs(A[i - 1] - A[i]);
    }
    total += abs(A[N - 1] - 0);
 
    for (int i = 0; i < N; ++i) {
        if (i == 0) {
            cout << total - abs(A[i] - 0) - abs(A[i] - A[i + 1]) + abs(0 - A[i + 1]) << endl;
        }
        else if (i == N - 1) {
            cout << total - abs(A[i] - A[i - 1]) - abs(A[i] - 0) + abs(A[i - 1] - 0) << endl;
        }
        else {
            cout << total - abs(A[i] - A[i - 1]) - abs(A[i] - A[i + 1]) + abs(A[i - 1] - A[i + 1]) << endl;
        }
    }
}
 
int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}