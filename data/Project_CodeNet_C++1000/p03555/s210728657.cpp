#include "bits/stdc++.h"

using namespace std;

void Main() {
    string C1, C2;
    cin >> C1;
    cin >> C2;

    if (C1[0] == C2[2] && C1[1] == C2[1] && C1[2] == C2[0]) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
