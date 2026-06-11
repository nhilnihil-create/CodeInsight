#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    string s; cin >> s;
    if (s.length() < 26) {
        char c = 'a';
        while (s.find(c) != string::npos) c++;
        return !(cout << s + c << endl);
    }
    string t(s);
    if (next_permutation(begin(s), end(s))) {
        int pref = 0;
        while (s[pref] == t[pref]) pref++;
        cout << s.substr(0, pref + 1) << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}
