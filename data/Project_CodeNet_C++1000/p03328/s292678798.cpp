#include <iostream>
#include <algorithm>

int main() {
    using namespace std;

    int a, b;
    cin >> a >> b;

    int w = 1;
    int e = 1;
    for (int i=2; i<=999; i++) {
        e = w + i;

        if (w - a == e - b) {
            cout << w - a << endl;
            break;
        }

        w = e;
    }

    return 0;
}