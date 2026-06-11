#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int a = (s[0] - '0') * 10 + (s[1] - '0');
    int b = (s[2] - '0') * 10 + (s[3] - '0');
    if(a >= 1 && a <= 12) {
        if(b >= 1 && b <= 12) {
            cout << "AMBIGUOUS";
        } else {
            cout << "MMYY";
        }
    } else {
        if(b >= 1 && b <= 12) {
            cout << "YYMM";
        } else {
            cout << "NA";
        }
    }
    return 0;
}