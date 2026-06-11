#include "bits/stdc++.h"

using namespace std;

void Main() {
    int A, B, C;
    cin >> A >> B >> C;
    if (A == B) {
        cout << C << endl;
    }
    else if (B == C) {
        cout << A << endl;
    }
    else {
        cout << B << endl;
    }
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
