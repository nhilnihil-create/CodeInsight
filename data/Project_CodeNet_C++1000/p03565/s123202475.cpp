#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    string str;
    string ans;
    string kekka = "";
    bool chk = false;
    cin >> str >> ans;

    if (str.size() < ans.size()) {
        cout << "UNRESTORABLE" << endl;
        return 0;
    }

    reverse(str.begin(), str.end());
    reverse(ans.begin(), ans.end());

    for (int i = 0; i <= str.size() - ans.size(); i++) {
        chk = false;
        for (int j = 0; j < ans.size(); j++) {
            // cout << i << "," << j << "==" << str.at(i + j) << ":" << ans.at(j) << endl;
            if (str.at(i + j) == ans.at(j) || str.at(i + j) == '?') {
                chk = true;
            } else {
                chk = false;
                break;
            }
        }

        if (chk == true) {
            if (i == 0) {
                // cout << ans;
                kekka += ans;
                for (int j = ans.size(); j < str.size(); j++) {
                    if (str.at(j) == '?') {
                        kekka += 'a';
                        // cout << 'a';
                    } else {
                        kekka += str.at(j);
                        // cout << str.at(j);
                    }
                }
            } else {
                for (int j = 0; j <= i - 1; j++) {
                    if (str.at(j) == '?') {
                        kekka += 'a';
                        // cout << 'a';
                    } else {
                        kekka += str.at(j);
                        // cout << str.at(j);
                    }
                }
                // cout << ans;
                kekka += ans;
                for (int j = i + ans.size(); j < str.size(); j++) {
                    if (str.at(j) == '?') {
                        kekka += 'a';
                        // cout << 'a';
                    } else {
                        kekka += str.at(j);
                        // cout << str.at(j);
                    }
                }
            }
            reverse(kekka.begin(), kekka.end());
            cout << kekka;
            cout << endl;
            return 0;
        }
    }

    cout << "UNRESTORABLE" << endl;
    //
}