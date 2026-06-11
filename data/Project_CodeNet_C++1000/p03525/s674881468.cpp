#include <algorithm>
#include <climits>
#include <cmath>
#include <csignal>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>

using ll = long long;
using namespace std;

int dif(int a, int b) {
    int tmp = abs(a - b);
    return min(tmp, 24-tmp);
}

int main() {
    int n = 0;
    cin >> n;
    int buf = 0;
    vector<int> d(13);
    d.at(0) = 1;
    for (int i=0; i<n; i++) {
        cin >> buf;
        d.at(buf)++;
    }
    for (int i=0; i<13; i++) {
        if (d.at(i) > 2) {
            cout << 0 << endl;
            return 0;
        }
        if (i == 0 || i == 12) {
            if (d.at(i) > 1) {
                cout << 0 << endl;
                return 0;
            }
        }
    }
    vector<bool> time(24, false);
    bool flag = true;
    for (int i=0; i<13; i++) {
        if (d.at(i) == 1) {
            if (flag) {
                time.at(i) = true;
                flag = false;
            }
            else {
                time.at(24-i) = true;
                flag = true;
            }
        }
        else if (d.at(i) == 2) {
            time.at(i) = time.at(24-i) = true;
        }
    }
    int mini = 100;
    for (int i=0; i<24; i++) {
        for (int j=0; j<24; j++) {
            if (i == j) {
                continue;
            }
            if (time.at(i) && time.at(j)) {
                mini = min(mini, dif(i, j));
            }
        }
    }
    cout << mini << endl;
    return 0;
}
