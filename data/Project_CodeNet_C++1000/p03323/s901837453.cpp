#include <iostream>
#include <vector>
#include <string>
#include <cmath>
 
using namespace std;
using Int = long long int;
using UInt = unsigned long long int;
using VI = vector<long long int>;

int main(void) {
    Int a, b;
    cin >> a >> b;
    if (a <= 8 && b <= 8) {
        cout << "Yay!" << endl;
    } else {
        cout << ":(" << endl;
    }
    return 0;
}

