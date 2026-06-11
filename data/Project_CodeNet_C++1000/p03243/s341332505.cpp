#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    while(1) {
        string s = to_string(n);
        if (s[0]==s[1] && s[1]==s[2]) {
            cout << n << endl;
            return 0;
        }
        n++;
    }
}