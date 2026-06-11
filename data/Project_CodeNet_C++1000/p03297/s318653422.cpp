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
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        long long int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a < b || b > d) {
            cout << "No" << endl;
            continue;
        }

        // [c + 1, b - 1]

        long long int bd = gcd(b, d);
        if (c + 1 > b - 1) {
            cout << "Yes" << endl;
            continue;
        }
        if (a >= c + 1 && a <= b - 1) {
            cout << "No" << endl;
            continue;
        }
        a = (a - b) % bd + b;
        a -= bd;
        if (a <= b - 1 && a >= c + 1) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    }
}


