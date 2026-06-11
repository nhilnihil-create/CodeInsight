#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    vector<int> A(3, 0); cin >> A[0] >> A[1] >> A[2];
    sort(A.begin(), A.end());
    printf("%d\n", (A[0] * A[1]) / 2); 
}