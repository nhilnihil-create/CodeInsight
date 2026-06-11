#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if (b / a < c) {
        cout << b / a;
    }
    else {
        cout << c;
    }
    return 0;
}
