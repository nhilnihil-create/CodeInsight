#include <bits/stdc++.h>
using namespace std;

bool is_acgt(string t) {
    for (auto iter = begin(t); iter != end(t); ++iter) {
        if (*iter != 'A' && *iter != 'C' && *iter != 'G' && *iter != 'T') {
            return false;
        }
    }
    return true;   
}


int main() {
    string s;
    cin >> s;
    int n = s.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (is_acgt(s.substr(i, j - i + 1))) {
                ans = max(ans, j - i + 1);
            }
        }
    }
    cout << ans << endl;
    return 0;
}