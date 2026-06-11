#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    string A, B, C;
    cin >> N >> A >> B >> C;
    int changes = 0;

    for (int i = 0; i < N; i++) {
        if (A[i] == B[i] && B[i] == C[i])
            continue;

        if (A[i] == B[i] || B[i] == C[i] || C[i] == A[i])
            changes++;
        else
            changes += 2;
    }

    cout << changes << '\n';
}
