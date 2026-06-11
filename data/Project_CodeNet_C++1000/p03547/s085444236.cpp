#include "bits/stdc++.h"

using namespace std;

void Main() {
    char X, Y;
    cin >> X >> Y;
    if (X - Y > 0) {
        cout << ">" << endl;
    }
    else if (X - Y < 0) {
        cout << "<" << endl;
    }
    else {
        cout << "=" << endl;
    }
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
