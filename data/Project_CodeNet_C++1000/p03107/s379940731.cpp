#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <climits>
#include <algorithm>
#include <utility>
 
using namespace std;
using Int = long long int;
using UInt = unsigned long long int;
using VI = vector<long long int>;

int main(void) {
    string s;
    cin >> s;
    Int length = (Int)s.length();
    Int result = length;
    Int count = 0;
    for (Int i = 0; i < length; ++i) {
        if (s[i] == '0') {
            count++;
        } else {
            count--;
        }
    }
    if (count < 0) {
        count *= (-1);
    }
    result -= count;
    cout << result << endl;
    return 0;
}

