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
    Int d;
    cin >> d;
    cout << "Christmas";
    for (Int i = 24; i >= d; --i) {
        cout << " Eve";
    }
    cout << endl;
    return 0;
}

