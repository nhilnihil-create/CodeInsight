#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

int ctoi(const char c) {
    switch (c) {
        case 'A': return 10; break;
        case 'B': return 11; break;
        case 'C': return 12; break;
        case 'D': return 13; break;
        case 'E': return 14; break;
        case 'F': return 15; break;
    }
}

int main() {
    char X, Y;

    cin >> X >> Y;

    if (ctoi(X) > ctoi(Y)) {
        cout << ">" << endl;
    } else if (ctoi(X) < ctoi(Y)) {
        cout << "<" << endl;
    } else if (ctoi(X) == ctoi(Y)) {
        cout << "=" << endl;
    }

    return 0;
}
