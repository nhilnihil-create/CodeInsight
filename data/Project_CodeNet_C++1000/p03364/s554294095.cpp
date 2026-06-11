#include <bits/stdc++.h>
using namespace std;

bool is_ok(const vector<string>& s) {
    for (int i = 0; i < (int)s.size(); i++) {
        for (int j = i; j < (int)s.size(); j++) {
            if (s[i][j] != s[j][i]) return false;
        }
    }
    return true;
}

void rotation(vector<string>& s) {
    for (int i = 1; i < (int)s.size(); i++) {
        swap(s[i-1], s[i]);
    }
}

int main() {
    int n, ans = 0;
    cin >> n;
    vector<string> s(n);
    for (auto& e : s) cin >> e;
    
    for (int _ = 0; _ < n; _++) {
        if (is_ok(s)) ans += n;
        rotation(s);
    }
    
    cout << ans << endl;
    return 0;
}