#include <bits/stdc++.h>

using namespace std;


int main() {
    int a = 0, b = 0;
    cin >> a >> b;

    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < b; ++j) {
            for (int c = 1; c <= 3; ++c) {
                if ((a * b * c) % 2 == 1) {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "No" << endl;
}