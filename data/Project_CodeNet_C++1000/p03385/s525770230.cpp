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
    if ((s.find('a') != string::npos) && (s.find('b') != string::npos) && (s.find('c') != string::npos)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
