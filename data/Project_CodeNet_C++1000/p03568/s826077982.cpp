#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int evenCnt = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] % 2 == 0) {
            evenCnt++;
        }
    }

    cout << pow(3, N) - pow(2, evenCnt) << endl;

    return 0;
}