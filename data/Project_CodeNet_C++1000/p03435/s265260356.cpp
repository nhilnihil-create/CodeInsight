#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include <math.h>
#include <set>
#include <deque>
#include <queue>
using namespace std;
typedef long long ll;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int a[4] = {} , b[4] = {} , c[4][4] = {};
    for (int i = 1 ; i <= 3 ; i++) {
        for (int j = 1 ; j <= 3 ; j++) cin >> c[i][j];
    }
    a[2] = c[2][1] - c[1][1];
    a[3] = c[3][1] - c[1][1];
    b[1] = c[1][1];
    b[2] = c[1][2];
    b[3] = c[1][3];
    for (int i = 1 ; i <= 3 ; i++) {
        for (int j = 1 ; j <= 3 ; j++) {
            if ((a[i] + b[j]) != c[i][j]) {
                cout << "No";
                return 0;
            }
        }
    }
    cout << "Yes";
}