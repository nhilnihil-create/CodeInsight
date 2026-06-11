#include <iostream>
#include <vector>
#include <string>

using namespace std;
using Int = long long int;
using UInt = unsigned long long int;
using VI = vector<unsigned long long int>;

int main(void) {
    char c[9];
    for (Int i = 0; i < 9; ++i) {
        cin >> c[i];
    }
    cout << c[0] << c[4] << c[8] << endl;
    return 0;
}
