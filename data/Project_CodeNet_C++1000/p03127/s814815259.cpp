#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<long int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    while (1) {
        sort(A.begin(), A.end());
        A.erase(remove(A.begin(), A.end(), 0), A.end());
        if (A.size() == 1) {
            cout << A[0] << endl;
            return 0;
        }
        for (int i = 1; i < N; i++) {
            A[i] = A[i] % A[0];
        }
    }
}
