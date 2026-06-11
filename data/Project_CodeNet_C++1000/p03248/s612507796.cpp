#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    string s; cin >> s;
    int n = s.length();
    s = " " + s;
    if (s[1] == '0' || s[n] == '1') return !(cout << -1 << endl);
    for (int i = 1; i < n; i++) {
        if (s[i] != s[n - i]) return !(cout << -1 << endl);
    }
    int p = 1;
    for (int i = 2; i < n; i++) if (s[i] == '1') {
        while (p < i) cout << p << " " << i << endl, p++;
    }
    cout << n - 1 << " " << n << endl;
    return 0;
}
