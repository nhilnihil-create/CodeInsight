#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;
int main() {
    vector<int> A(3, 0);
    int K; cin >> A[0] >> A[1] >> A[2] >> K;
    sort(A.begin(), A.end(), greater<int>());
    for (int i = 0; i < K; i++) {
        A[0] *= 2; sort(A.begin(), A.end(), greater<int>());
    }
    printf("%d\n", A[0] + A[1] + A[2]);
}
