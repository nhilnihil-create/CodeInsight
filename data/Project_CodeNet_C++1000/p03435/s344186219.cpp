#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> c(3, vector<int>(3));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> c.at(i).at(j);
        }
    }
    for (int i = 0; i < 3; i++) {
        if (c.at(0).at(i % 3) - c.at(0).at((i + 1) % 3) != c.at(1).at(i % 3) - c.at(1).at((i + 1) % 3)
        || c.at(1).at(i % 3) - c.at(1).at((i + 1) % 3) != c.at(2).at(i % 3) - c.at(2).at((i + 1) % 3)
        || c.at(i % 3).at(0) - c.at((i + 1) % 3).at(0) != c.at(i % 3).at(1) - c.at((i + 1) % 3).at(1)
        || c.at(i % 3).at(1) - c.at((i + 1) % 3).at(1) != c.at(i % 3).at(2) - c.at((i + 1) % 3).at(2)) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}
