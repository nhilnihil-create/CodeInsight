#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;

int main() { 
    vector<vector<int>> v(3, vector<int>(3, 0));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> v[i][j];
        }
    }
    int last1 = 0x3f3f3f3f, last2 = 0x3f3f3f3f;
    for (int i = 0; i < 3; i++) {
        if (last1 != 0x3f3f3f3f && v[i][0] - v[i][1] != last1) {
            cout << "No" << endl;
            return 0;
        } else {
            last1 = v[i][0] - v[i][1];
        }
        if (last2 != 0x3f3f3f3f && v[i][2] - v[i][1] != last2) {
            cout << "No" << endl;
            return 0;
        } else {
            last2 = v[i][2] - v[i][1];
        }
    }
    last1 = 0x3f3f3f3f, last2 = 0x3f3f3f3f;
    for (int i = 0; i < 3; i++) {
        if (last1 != 0x3f3f3f3f && v[0][i] - v[1][i] != last1) {
            cout << "No" << endl;
            return 0;
        } else {
            last1 = v[0][i] - v[1][i];
        }
        if (last2 != 0x3f3f3f3f && v[2][i] - v[1][i] != last2) {
            cout << "No" << endl;
            return 0;
        } else {
            last2 = v[2][i] - v[1][i];
        }
    }
    cout << "Yes" << endl;
}


