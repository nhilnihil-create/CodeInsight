#include "bits/stdc++.h"

using namespace std;

void Main() {
    vector<vector<int> > c(3, vector<int>(3, 0));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> c[i][j];
        }
    }

    for (int a1 = -100; a1 <= 100; ++a1) {
        for (int a2 = -100; a2 <= 100; ++a2) {
            for (int a3 = -100; a3 <= 100; ++a3) {
                bool ok = true;
                int b1 = c[0][0] - a1;
                int b2 = c[1][1] - a2;
                int b3 = c[2][2] - a3;
                if (c[1][0] == a2 + b1 && c[2][0] == a3 + b1
                    && c[0][1] == a1 + b2 && c[2][1] == a3 + b2
                    && c[0][2] == a1 + b3 && c[1][2] == a2 + b3) {
                    cout << "Yes" << endl;
                    return;
                }
            }
        }
    }
    cout << "No" << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
