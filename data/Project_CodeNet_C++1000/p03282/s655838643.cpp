#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <utility>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    string s;
    long k;
    cin >> s >> k;
    size_t first = s.find_first_not_of("1");
    if (first == string::npos) {
        cout << s[0] << endl;
    } else if (k > first) {
        cout << s[first] << endl;
    } else {
        cout << "1" << endl;
    }
}
