#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    long long k;
    cin >> s >> k;
    int a, b = INT_MAX;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != '1') {
            a = s[i] - '0';
            b = i + 1;
            break;
        }
    }
    if (k < b) cout << 1 << endl; 
    else cout << a << endl;
}