#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <utility>
#include <string>
#include <vector>

using namespace std;

int main() {
    long n;
    cin >> n;
    long nn = n + 2;
    long l = 1;
    while (l <= abs(n)) {
        l *= 4;
        nn += 2 * l;
    }
    vector<int> rem;
    while (nn > 0) {
        rem.push_back(nn % 4);
        nn /= 4;
    }
    string ans = "0";
    for (int i = rem.size()-1; i >= 0; i--) {
        if (rem[i] == 0) ans += "10";
        else if (rem[i] == 1) ans += "11";
        else if (rem[i] == 2) ans += "00";
        else ans += "01";
    }
    size_t first = ans.find("1");
    if (first == string::npos) {
        cout << "0" << endl;
    } else {
        cout << ans.substr(first) << endl;
    }
}
