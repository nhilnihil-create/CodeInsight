#include <iostream>

using namespace std;
using LL = long long;

int main() {
    LL X, Y;
    cin >> X >> Y;

    int i = 0;
    while (X <= Y) {
        X *= 2;
        i++;
    }

    cout << i << endl;
}