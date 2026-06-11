#include <iostream>
#include <vector>
#include <string>

using namespace std;
using Int = long long int;
using UInt = unsigned long long int;
using VI = vector<unsigned long long int>;

int main(void) {
    string s;
    cin >> s;
    UInt len = s.length();
    Int k;
    cin >> k;
    for (Int i = 1; i <= len; ++i) {
        if (s[i - 1] == '1' && k == i) {
            cout << '1' << endl;
            break;
        } else if (s[i - 1] != '1') {
            cout << s[i - 1] << endl;
            break;
        }
    }
}
