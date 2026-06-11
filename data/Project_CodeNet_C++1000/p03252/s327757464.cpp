#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    vector<int> u(30, -1), v(30, -1);
    cin >> s >> t;
    for (size_t i = 0; i < s.size(); i++) {
        int p = s[i] - 'a', q = t[i] - 'a';
        if (u[p] == -1) u[p] = q;
        else if (u[p] != q) {
            cout << "No" << endl;
            return 0;
        }
        if (v[q] == -1) v[q] = p;
        else if (v[q] != p) {
            cout << "No" << endl;
            return 0;
        }        
    }
    cout << "Yes" << endl;
    return 0;
}