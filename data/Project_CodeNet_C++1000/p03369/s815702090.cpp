#include <iostream>
#include <vector>
#include <string>
#include <cmath>
 
using namespace std;
using Int = long long int;
using UInt = unsigned long long int;
using VI = vector<long long int>;

int main(void) {
    string s;
    cin >> s;
    Int cost = 700;
    for (Int i = 0; i < (Int)s.length(); ++i) {
        if (s[i] == 'o') {
            cost += 100;
        }
    }
    cout << cost << endl;
    return 0;
}
