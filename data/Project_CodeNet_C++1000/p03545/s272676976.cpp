#include <bits/stdc++.h>
using namespace std;

int main () {
    string s;
    cin >> s;
    int a = s[0] - '0', b = s[1] - '0', c = s[2] - '0', d = s[3] - '0';
 
    bool con = 1;
    for (int i = -1; i < 2; i = i + 2)
        for (int j = -1; j < 2; j = j + 2)
            for (int k = -1; k < 2; k = k + 2) {
                if (((a + (b * i) + (c * j) + (d * k)) == 7) && (con)) {
                    cout << a << ((i == 1) ? '+' : '-') << b << ((j == 1) ? '+' : '-') << c << ((k == 1) ? '+' : '-') << d << "=7" << endl;
                    con = 0;
                }
            }
}   