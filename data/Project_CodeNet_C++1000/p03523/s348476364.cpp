#include <bits/stdc++.h>
using namespace std;
#define vec(type) vector<type>

int main() {
    string s;
    cin >> s;

    string a = "AKIHABARA";
    for (int i = 0; i < 9; i++) {
        if (s[i] != a[i]) {
            s.insert(i,"A");
            if (s[i] != a[i]) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    if (s.size() != 9) cout << "NO" << endl;
    else cout << "YES" << endl;
}