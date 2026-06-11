#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <random>
#include <fstream>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    string s, t;
    cin >> s >> t;
    if (s.length() < t.length()) {
        cout << "UNRESTORABLE";
        return 0;
    }
    for (int i = (int)(s.length() - t.length()); i >= 0; i--) {
        bool y = 0;
        for (int j = 0; j < t.length(); j++) if (s[j + i] != '?' && s[j + i] != t[j]) y = 1;
        if (y == 0) {
            for (int j = 0; j < t.length(); j++) s[j + i] = t[j];
            for (int j = 0; j < s.length(); j++) if (s[j] == '?') s[j] = 'a';
            cout << s;
            return 0;
        }
    }
    cout << "UNRESTORABLE";
}
