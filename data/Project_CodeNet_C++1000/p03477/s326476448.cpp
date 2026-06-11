#include<bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, d, left, right;
    cin >> a >> b >> c >> d;
    left = a + b;
    right = c + d;
    if (left > right) {
        cout << "Left" << endl;
    } else if (left == right) {
        cout << "Balanced" << endl;
    } else {
        cout << "Right" << endl;
    }
    return 0;
}