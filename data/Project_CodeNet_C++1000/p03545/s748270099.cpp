#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int sum = 0;    
    for (int i = 0; i < (1 << 3); i++) {
        for (int j = 0; j < 3; j++) {
            if (i & (1 << j)) sum += s.at(3 - j) - '0';
            else sum -= s.at(3 - j) - '0';
        }
        sum += s.at(0) - '0';
        if (sum == 7) {
            string ans = "";
            ans += s.at(0);
            for (int j = 2; j >= 0; j--) {
                if (i & (1 << j)) ans += '+';
                else ans += '-';
                ans += s.at(3 - j);
            }
            ans += "=7";
            cout << ans << endl;
            break;
        }
        sum = 0;
    }
}
