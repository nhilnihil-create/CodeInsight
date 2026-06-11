#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s; int s_len = s.size();
    string key = "keyence";
    int check = 0;
    for (int i = 0; i < 7; i++) {
        if (key.at(i) == s.at(i)) {
            check++;
        } else break;
    }
    if (check == 7) {
        cout << "YES" << endl;
        return 0;
    }
    for (int i = s_len-7+check; i < s_len; i++) {
        if (key.at(check) == s.at(i)) {
            check++;
        } else break;
    }
    if (check == 7) {
        cout << "YES" << endl;
        return 0;
    } else {
        cout << "NO" << endl;
        return 0;
    }
}