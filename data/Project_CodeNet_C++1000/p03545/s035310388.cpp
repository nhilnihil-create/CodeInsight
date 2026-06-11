/**
 *    author:  FromDihPout
 *    created: 2020-08-10
**/

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    cin >> s;
    
    for (int i = 0; i < 1<<3; i++) {
        int num = s[0] - '0';
        for (int j = 0; j < 3; j++) {
            if (1<<j & i)
                num += s[j+1] - '0';
            else
                num -= s[j+1] - '0';
        }
      
        if (num == 7) {
            for (int j = 0; j < 3; j++) {
                cout << s[j];
                if (1<<j & i)
                    cout << '+';
                else
                    cout << '-';
            }
            cout << s[3] << "=7" << '\n';
            break;
        }
    }
    
    return 0;
}