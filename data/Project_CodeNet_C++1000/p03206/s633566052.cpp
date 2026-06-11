#include "bits/stdc++.h"

using namespace std;

void Main() {
    int D;
    cin >> D;
    switch (D) {
    case 25:
        cout << "Christmas";
        break;
    case 24:
        cout << "Christmas Eve";
        break;
    case 23:
        cout << "Christmas Eve Eve";
        break;
    case 22:
        cout << "Christmas Eve Eve Eve";
        break;
    default:
        ;
    }
    cout << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
