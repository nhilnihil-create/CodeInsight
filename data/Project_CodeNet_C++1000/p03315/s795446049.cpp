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
    Int count = 0;
    for (Int i = 0; i < s.length(); ++i) {
        if (s[i] == '+') {
            count++;
        } else {
            count--;
        }
    }
    cout << count << endl;
    return 0;
}

