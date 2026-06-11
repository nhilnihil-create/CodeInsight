#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;


int main() {
    string s;
    cin >> s;
    if (s[0] != 'A') {
        cout << "WA" << endl;
        return 0;
    }
    int c = 0;
    for (int i = 2; i < s.size() - 1; i++) {
        if (s[i] == 'C') {
            c++;
        }
    }
    if (c != 1) {
        cout << "WA" << endl;
        return 0;
    }
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'A' || s[i] == 'C' || (s[i] >= 'a' && s[i] <= 'z')) {

        } else {
            cout << "WA" << endl;
            return 0;
        }
    }
    cout << "AC" << endl;
}
