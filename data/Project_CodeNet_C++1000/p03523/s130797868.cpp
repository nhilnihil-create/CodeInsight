#include <bits/stdc++.h>

using namespace std;

string f(const string &s) {
    string res;
    for (auto c:s) if (c != '0') res += c;
    return res;
}

int main() {
    string t = "AKIHABARA";
    int a[] = {0, 4, 6, 8};
    set<string> st;
    for (unsigned int bit = 0; bit < (1u << 4u); ++bit) {
        string tt = t;
        for (unsigned int j = 0; j < 4; ++j) {
            if (bit & (1u << j)) {
                tt[a[j]] = '0';
            }
            st.insert(f(tt));
        }
    }

    string s;
    cin >> s;
    if (st.find(s) != st.end()) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}