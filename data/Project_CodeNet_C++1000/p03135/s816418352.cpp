#include <iostream>
#include <iomanip>
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
    Int t, x;
    cin >> t >> x;
    double result = (double)t / (double)x;
    cout << fixed << setprecision(10) << result << endl;
    return 0;
}

