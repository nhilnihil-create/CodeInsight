#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <climits>
#include <cassert>
#include <algorithm>
#include <utility>

using namespace std;
using Int = long long int;
using UInt = unsigned long long int;
using VI = vector<long long int>;
using VVI = vector<vector<long long int> >;

int main(void) {
    VI n(4);
    for (Int i = 0; i < 4; ++i) {
        cin >> n[i];
    }
    sort(n.begin(), n.end());
    if (n[0] == 1 && n[1] == 4 && n[2] == 7 && n[3] == 9) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
