#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    string s;
    cin >> s;
    string key = "keyence";
    int n = s.size();
    for (int i = 0; i <= n - 7; i++) {
        if (i == 0) {
            if (s == key) {
                cout << "YES" << endl;
                return 0;
            }
            continue;
        }
        for (int j = 0; j <= n - i; j++) {
            string t;
            int rem = i;
            bool flag = true;
            for (int k = 0; k < n; k++) {
                if (!flag) rem--;
                if (k == j) {
                    rem--;
                    flag = false;
                }
                if (flag) t += s[k];
                if (rem == 0) {
                    flag = true;
                }
            }
            if (t == key) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
}