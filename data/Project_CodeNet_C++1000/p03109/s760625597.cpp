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
    string now = "2019/04/30";
    string s;
    cin >> s;
    if (s <= now) {
        cout << "Heisei" << endl;
    } else {
        cout << "TBD" << endl;
    }
    return 0;
}

