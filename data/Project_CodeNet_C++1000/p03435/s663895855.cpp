#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<vector<int>> v(3, vector<int>(3));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> v[i][j];
        }
    }

    bool ret = true;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (v[i][j] - v[i][j + 1] != v[i + 1][j] - v[i + 1][j + 1])ret = false;
            if (v[j][i] - v[j][i + 1] != v[j + 1][i] - v[j + 1][i + 1])ret = false;
        }
    }

    cout << (ret ? "Yes" : "No") << endl;
    return 0;
}