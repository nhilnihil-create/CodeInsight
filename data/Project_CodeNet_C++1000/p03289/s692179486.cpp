#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <regex>
#include <utility>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;
    smatch m;
    if (regex_match(s, m, regex("A[a-z]+C[a-z]+"))) {
        cout << "AC" << endl;
    } else {
        cout << "WA" << endl;
    }
}
