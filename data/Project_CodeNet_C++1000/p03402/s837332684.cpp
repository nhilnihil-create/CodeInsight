#include "bits/stdc++.h"

using namespace std;

void Main() {
    int A, B;
    cin >> A >> B;

    vector<vector<int>> ans(100, vector<int>(100, 0));
    int i = 1;
    int j = 1;
    bool makeBlock = false;
    while (A > 1) {
        makeBlock = true;
        ans[3 * i - 3][3 * j - 3] = 1;
        ans[3 * i - 3][3 * j - 2] = 1;
        ans[3 * i - 3][3 * j - 1] = 1;

        ans[3 * i - 2][3 * j - 3] = 1;
        ans[3 * i - 2][3 * j - 2] = 0;
        ans[3 * i - 2][3 * j - 1] = 1;

        ans[3 * i - 1][3 * j - 3] = 1;
        ans[3 * i - 1][3 * j - 2] = 1;
        ans[3 * i - 1][3 * j - 1] = 1;
        --A;
        ++j;
        if (3 * j - 1 > 98) {
            j = 1;
            ++i;
        }
    }
    if (makeBlock) {
        --B;
    }
    i = 0;
    j = 0;
    while (B > 0) {
        ans[99 - i][99 - j] = 1;
        --B;
        j += 2;
        if (99 - j < 0) {
            j = 0;
            i += 2;
        }
    }

    cout << 100 << " " << 100 << endl;
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            cout << (ans[i][j] == 1 ? '#' : '.');
        }
        cout << endl;
    }
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
