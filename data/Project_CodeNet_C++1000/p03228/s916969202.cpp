#include <algorithm>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;
#define ALL(x) (x).begin(), (x).end()
#define OUT(x) cout << (x) << endl
typedef long long ll;

int main() {
    int a, b, k;
    cin >> a >> b >> k;
    bool flag = true;
    while (k) {
        if (flag) {
            if (a % 2) {
                a--;
            }
            b += a / 2;
            a /= 2;
            flag = false;
        } else {
            if (b % 2) {
                b--;
            }
            a += b / 2;
            b /= 2;
            flag = true;
        }
        k--;
    }
    cout << a << " " << b << endl;
}
