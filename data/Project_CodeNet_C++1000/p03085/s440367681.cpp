#include <iostream>

using namespace std;

int main() {
    char a;
    cin >> a;
    if (a == 'A') {
        cout << 'T';
    }
    else if (a == 'T') {
        cout << 'A';
    }
    else if (a == 'G') {
        cout << 'C';
    }
    else {
        cout << 'G';
    }
    return 0;
}
