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
    Int n, k;
    string s;
    cin >> n >> k >> s;
    --k;
    Int diff = 'a' - 'A';
    s[k] += diff;
    cout << s << endl;
    return 0;
}

