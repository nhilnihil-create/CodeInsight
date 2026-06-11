#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    string s;
    cin >> a >> b >> s;

    if (s.length() == a+b+1) {
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '-')
                count++;
        }
        if (count == 1) {
            if (s[a] == '-') {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}