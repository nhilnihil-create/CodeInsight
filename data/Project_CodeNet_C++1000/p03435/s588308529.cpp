#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <iomanip>
#include <queue>
#include <numeric>

using namespace std;

int main() {

    bool ans = true;
    vector<vector<int>> c(3, vector<int>(3));

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> c[i][j];
        }
    }

    for (int i = 0; i < 2; i++) {

        if (!(c[i][0] - c[i + 1][0] == c[i][1] - c[i + 1][1] && c[i][1] - c[i + 1][1] == c[i][2] - c[i + 1][2])) {
            ans = false;
        }
        if (!(c[0][i] - c[0][i + 1] == c[1][i] - c[1][i + 1] && c[1][i] - c[1][i + 1] == c[2][i] - c[2][i + 1])) {
            ans = false;
        }
    }

    if (ans) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }

	return 0;
}
