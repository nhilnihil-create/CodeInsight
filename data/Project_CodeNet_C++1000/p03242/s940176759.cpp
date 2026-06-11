#include <iostream>
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
    for (Int i = 0; i < (Int)s.length(); ++i) {
        if (s[i] == '1') {
            s[i] = '9';
        } else {
            s[i] = '1';
        }
    }
    cout << s << endl;
    return 0;
}

