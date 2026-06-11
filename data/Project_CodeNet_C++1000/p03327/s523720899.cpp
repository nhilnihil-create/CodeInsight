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
    int n;
    cin >> n;
    if (n <= 999) {
        cout << "ABC";
    } else {
        cout << "ABD";
        n -= 999;
    }
    cout << endl;
    return 0;
    if (n < 10) {
        cout << "00" << n;
    } else if (n < 100) {
        cout << "0" << n;
    } else {
        cout << n;
    }
    cout << endl;
}
