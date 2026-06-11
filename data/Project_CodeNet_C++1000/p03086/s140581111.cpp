#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    string s;
    cin >> s;

    int max = 0;
    int cnt = 0;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'A' || s[i] == 'C' || s[i] == 'G' || s[i] == 'T') {
            cnt++;
            if (i == s.length() - 1) {
                if (cnt > max) max = cnt;
            }
        }
        else {
            if (cnt > max) max = cnt;
            cnt = 0;
        }
    }

    cout << max << endl;
    return 0;
}