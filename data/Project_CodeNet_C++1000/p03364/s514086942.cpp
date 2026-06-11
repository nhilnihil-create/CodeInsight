#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; cin >> n;
    vector<string> s(n);
    for (auto &si: s) cin >> si;
    auto check = [&](vector<string> &s) {
        for (int i = 0; i < n; i++) for (int j = 0; j < i; j++) {
            if (s[i][j] != s[j][i]) return false;
        }
        return true;
    };
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        rotate(s.begin(), s.begin() + 1, s.end());
        cnt += check(s);
    }
    cout << cnt * n << endl;
    return 0;
}
