#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    string res = "No", tmp;
    int size = 0;
    while (size < s.size()) {
        tmp = s.substr((s.size()-size), s.size());
        if ((tmp + s.substr(0, (s.size()-size))) == t) {
            res = "Yes";
            break;
        }
        size++;
    }

    cout << res << endl;    

    return 0;
}
