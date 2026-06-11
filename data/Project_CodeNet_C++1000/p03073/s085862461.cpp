#include <bits/stdc++.h>
     
using namespace std;
     
int main() {
    string s;
    cin >> s;
    int col = 0;
    int no_change = 0;
    for (int i = 0; i < s.length(); i++) {
        if ((s[i] - '0') != col) {
            no_change++;
        }
        col = 1 - col;
    }
    cout << min(no_change, (int)(s.length() - no_change));
}