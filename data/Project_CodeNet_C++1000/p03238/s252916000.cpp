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
    Int n;
    cin >> n;
    if (n == 1) {
        cout << "Hello World" << endl;
    } else {
        Int a, b;
        cin >> a >> b;
        cout << a + b << endl;
    }
    return 0;
}

