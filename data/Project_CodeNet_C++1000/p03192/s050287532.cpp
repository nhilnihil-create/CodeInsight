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
    string n;
    cin >> n;
    Int len = (Int)n.length();
    Int count = 0;
    for (Int i = 0; i < len; ++i) {
        if (n[i] == '2') {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}
