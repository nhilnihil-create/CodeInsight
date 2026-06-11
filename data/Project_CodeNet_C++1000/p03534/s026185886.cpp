#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
struct Solution {
    void solve(std::istream& in, std::ostream& out) {
        string s;
        in >> s;
        ll abc[3] = {};
        for (size_t i = 0; i < s.size(); i++) {
            abc[s[i] - 'a']++;
        }
        bool ans = 1 >= abs(abc[0] - abc[1]) && 1 >= abs(abc[1] - abc[2]) && 1 >= abs(abc[2] - abc[0]);
        out << (ans ? "YES" : "NO") << '\n';
    }
};
void solve(std::istream& in, std::ostream& out) {
    out << std::setprecision(12);
    Solution solution;
    solution.solve(in, out);
}
#include <fstream>
#include <iostream>
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    istream& in = cin;
    ostream& out = cout;
    solve(in, out);
    return 0;
}
