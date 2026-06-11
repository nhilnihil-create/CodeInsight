#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    
    bool same = true;
    if (s.size() < t.size()) {
        for (size_t i=0; i<s.size(); ++i) {
            if (s[i] != t[i]) {
                same = false;
            }
        }
        if (same) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    for (size_t i=0; i<t.size(); ++i) {
        if (t[i]>s[0]) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}
