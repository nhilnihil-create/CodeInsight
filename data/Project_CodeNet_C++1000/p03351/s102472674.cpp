#include "bits/stdc++.h"

using namespace std;

void Main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (abs(a - c) <= d) {
        cout << "Yes" << endl;
    }
    else if (abs(a - b) <= d && abs(b - c) <= d) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
