#include <bits/stdc++.h>
using namespace std;
int main () {
    int N;
    cin >> N;
    vector<int> A(N);
    long long p = 1, q = 1;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        p *= 3;
        if (A[i] % 2 == 0) {
            q *= 2;
        }
    }
    cout << p-q << endl;
}