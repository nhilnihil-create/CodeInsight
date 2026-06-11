#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define U(v) cerr << #v << ": " << (v) << endl

int main() {
    string s;
    while (cin >> s) {
        int ct[3]{};
        for (char c : s)
            ++ct[c - 'a'];
        int mn = min({ ct[0], ct[1], ct[2] });
        ct[0] -= mn;
        ct[1] -= mn;
        ct[2] -= mn;
        if (ct[0] >= 2 || ct[1] >= 2 || ct[2] >= 2)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}
