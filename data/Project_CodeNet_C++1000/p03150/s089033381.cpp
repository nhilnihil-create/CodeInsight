#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    string k = "keyence";
    for (int i = 0; i <= s.size()-7; i++) {
        for (int j = 0; j < s.size()-max(1,i); j++) {
            string t = s;
            t.erase (j, i);
            if (t == k) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
}