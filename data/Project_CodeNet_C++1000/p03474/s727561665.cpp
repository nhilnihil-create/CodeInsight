#include "bits/stdc++.h"

using namespace std;

bool solve(int A, int B, const string& S) {
    for (int i = 0; i < A; ++i) {
        if (S[i] == '-') {
            return false;
        }
    }
    if (S[A] != '-') {
        return false;
    }
    for (int i = 0; i < B; ++i) {
        if (S[A + i + 1] == '-') {
            return false;
        }
    }
    return true;
}

void Main() {
    int A, B;
    cin >> A >> B;
    string S;
    cin >> S;

    cout << (solve(A, B, S) ? "Yes" : "No") << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
