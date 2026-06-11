#include "bits/stdc++.h"

using namespace std;

void Main() {
    int A, B, X;
    cin >> A >> B >> X;
    bool yes = false;
    if (A <= X && X <= A + B) {
        yes = true;
    }
    cout << (yes ? "YES" : "NO") << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
