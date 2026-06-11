#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    bool can_transform = false;
    for (int x = 0; x < s.length(); x++) {
        if (s.substr(x) + s.substr(0, x) == t) {
            can_transform = true;
        }
    }
    if (can_transform) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
