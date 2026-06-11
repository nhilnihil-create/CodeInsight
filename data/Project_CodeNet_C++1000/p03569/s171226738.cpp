#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    string s;
    cin >> s;

    string t;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != 'x') {
            t += s[i];
        }
    }
    for (int i = 0; i < t.length(); i++) {
        if (t[i] != t[t.length() - i - 1]) {
            cout << -1 << endl;
            return 0;
        }
    }

    vector<int> x;
    int tmp = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'x') {
            tmp++;
        } else {
            x.push_back(tmp);
            tmp = 0;
        }
    }
    x.push_back(tmp);

    int output = 0;
    for (int i = 0; i < x.size(); i++) {
        if (x[i] != x[x.size() - i - 1]) {
            output += abs(x[i] - x[x.size() - i - 1]);
        }
    }

    cout << output / 2 << endl;

    return 0;
}
