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
    long long int k;
    cin >> k;
    for (int i = 0; i < s.size(); i++) {
        if (k == 1) {
            cout << s[i] << endl;
            return 0;
        }
        if (s[i] == '1') {
            k--;
        } else {
            cout << s[i] << endl;
            return 0;
        }
    }
}
