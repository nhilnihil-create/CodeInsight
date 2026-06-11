#include <iostream>
#include <map>

using namespace std;
using Int = long long int;
using UInt = unsigned long long int;

int main(void) {
    Int n;
    cin >> n;
    map<char, Int> c;
    string s;
    for (Int i = 0; i < n; ++i) {
        cin >> s;
        c[s[0]]++;
    }
    Int array[5];
    array[0] = c['M'];
    array[1] = c['A'];
    array[2] = c['R'];
    array[3] = c['C'];
    array[4] = c['H'];
    Int result = 0;
    for (Int i = 0; i < 5; ++i) {
        for (Int j = i + 1; j < 5; ++j) {
            for (Int k = j + 1; k < 5; ++k) {
                result += (array[i] * array[j] * array[k]);
            }
        }
    }
    cout << result << endl;
    return 0;
}

