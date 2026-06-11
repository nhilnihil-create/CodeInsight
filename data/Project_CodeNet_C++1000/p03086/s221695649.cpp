#include <bits/stdc++.h>

using namespace std;

bool is_acgt(string s) {
    for (char c : s) {
        if (c != 'A' && c != 'C' && c != 'G' && c != 'T') {
            return false;
        }
    }
    return true;
}

int main() {
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        for (int j = 1; j <= (int)s.size() - i; j++) {
            string t = s.substr(i, j);
            if (is_acgt(t) && j > ans) {
                ans = j;
            }
        }
    }

    cout << ans << endl;
}