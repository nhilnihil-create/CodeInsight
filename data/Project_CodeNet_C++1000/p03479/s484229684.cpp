#include <bits/stdc++.h>
using namespace std;

int main() {
    unsigned long long X, Y;
    cin >> X >> Y;
    int c = 0;
    while (X <= Y) {
        c++;
        X *= 2;
    }
    cout << c << endl;
}
