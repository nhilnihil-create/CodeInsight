#include <bits/stdc++.h>
using namespace std;

bool solve(int A, int B) {
    int C = 1;
    int count = 0;
    for (int i = 1; i <= 3; i++) {
        int x;
        x = A * B * C;
        if (x % 2 != 0) {
            count++;
        }
    }
    if (count > 0) {
        return true;
    }
    else {
        return false;
    }
}

int main() {

    int A, B;

    cin >> A >> B;

    if (solve(A, B) == true) {
        cout << "Yes" << endl;
    }

    else {
        cout << "No" << endl;
    }
}