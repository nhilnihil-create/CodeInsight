#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    int A[2], K;
    cin >> A[0] >> A[1] >> K;
    for (int i = 0; i < K; i++) {
        int t = i % 2;
        A[1 - t] += A[t] / 2;
        A[t] -= A[t] / 2 + (A[t] % 2);
    }
    cout << A[0] << " " << A[1] << endl;
}
