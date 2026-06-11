#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
int main() {
    string s;
    cin >> s;
    set<char> st;
    for (const auto c : s)
        st.insert(c);
    for (char c = 'a'; c <= 'z'; ++c) {
        if (!st.count(c)) {
            cout << s << c << '\n';
            return 0;
        }
    }
    string t = s;
    if (next_permutation(s.begin(), s.end())) {
        for (int i = 0; i < s.size(); ++i) {
            if (s.substr(0, i) > t) {
                cout << s.substr(0, i) << '\n';
                return 0;
            }
        }
    } else
        cout << -1 << '\n';
}