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
    int d, n;
    cin >> d >> n;
    if (d == 0) {
        if (n == 100) {
            cout << 101 << endl;
        } else {
            cout << n << endl;
        }
    } else {
        if (n == 100) {
            cout << n + 1;
        } else {
            cout << n;
        }
        cout << "00";
        if (d == 2) cout << "00" << endl;
    }
}
