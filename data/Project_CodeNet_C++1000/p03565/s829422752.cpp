#include <algorithm>
#include <bitset>
#include <climits>
#include <complex>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <thread>
#include <tuple>
#include <type_traits>
#include <vector>

#include <stdio.h>

using ll = long long;
using namespace std;

vector<vector<bool>> v;

int main() {
    ios::sync_with_stdio(false);
    string s, t;
    cin >> s >> t;

    for (int i = s.size() - t.size() + 1; i >= 0; i--) {
        bool ok = true;
        for (int j = 0; j < t.size(); j++) {
            if (s[i + j] == '?' || s[i + j] == t[j])
                continue;
            else {
                ok = false;
                break;
            }
        }
        if (ok) {
            // answer found
            for (int j = 0; j < t.size(); j++) {
                s[i + j] = t[j];
            }
            for (int k = 0; k < s.size(); k++) {
                if (s[k] == '?')
                    s[k] = 'a';
            }
            cout << s << endl;
            return 0;
        }
    }

    cout << "UNRESTORABLE " << endl;
    return 0;
}
