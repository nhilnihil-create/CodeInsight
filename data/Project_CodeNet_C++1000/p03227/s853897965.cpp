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
    string s;
    cin >> s;
    Int len = (Int)s.length();
    if (len == 2) {
    } else if (len == 3) {
        std::reverse(s.begin(), s.end());
    }
    cout << s << endl;
    return 0;
}
