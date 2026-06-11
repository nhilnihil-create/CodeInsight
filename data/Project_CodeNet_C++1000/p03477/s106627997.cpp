#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int A, B, C, D, left, right;
    cin >> A >> B >> C >> D;
    left = A + B;
    right = C + D;

    if (left > right) {
        cout << "Left" << endl;
    } else if (left == right) {
        cout << "Balanced" << endl;
    } else {
        cout << "Right" << endl;
    }

    return 0;
}
