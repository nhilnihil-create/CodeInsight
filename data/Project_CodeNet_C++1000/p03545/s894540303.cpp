#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    //入力
    int a, b, c, d;
    char op1, op2, op3;
    string input;
    cin >> input;
    a = input[0] - '0'; 
    b = input[1] - '0'; 
    c = input[2] - '0';
    d = input[3] - '0';
    for (int bit = 0; bit < (1<<3); bit++) {
        int ans = a;
        if (bit & (1<<2)) {
            op1 = '+';
            ans += b;
        }
        else {
            op1 = '-';
            ans -= b;
        }

        if (bit & (1<<1)) {
            op2 = '+';
            ans += c;
        }
        else {
            op2 = '-';
            ans -= c;
        }

        if (bit & 1) {
            op3 = '+';
            ans += d;
        }
        else {
            op3 = '-';
            ans -= d;
        }
        
        if (ans == 7) break;
    }
    cout << a << op1 << b << op2 << c << op3 << d << "=7" << endl;
    return 0;
}