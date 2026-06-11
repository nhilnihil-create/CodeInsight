#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <climits>
#include <algorithm>
#include <utility>
 
using namespace std;
using Int = long long int;
using UInt = unsigned long long int;
using VI = vector<long long int>;

int main(void) {
    map<char, char> mp;
    mp['A'] = 'T';
    mp['T'] = 'A';
    mp['C'] = 'G';
    mp['G'] = 'C';
    char c;
    cin >> c;
    cout << mp[c] << endl;
    return 0;
}

