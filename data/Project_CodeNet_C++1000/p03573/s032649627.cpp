#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

int main() {
    int A[3];

    for (int i = 0; i < 3; i++) {
        cin >> A[i];
    }

    sort(A, A + 3);

    if (A[0] == A[1]) {
        cout << A[2] << endl;
    } else if (A[1] == A[2]) {
        cout << A[0] << endl;
    }

    return 0;
}