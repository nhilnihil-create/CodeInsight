#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    vector<int> arr(4);
    for (int i = 0; i < 4; i++) {
        arr.at(i) = (int) S.at(i) - '0';
    }

    bitset<3> b;
    string formular;
    int ans;
    for (int tmp = 0; tmp < (1 << 3); tmp++) {
        b = tmp;
        ans = arr.at(0);
        formular = S.substr(0, 1);
        for (int i = 2; i >= 0; i--) {
            if (b.test(i)) {
                ans += arr.at(3 - i);
                formular = formular + "+" + S.substr(3 - i, 1);
            } else {
                ans -= arr.at(3 - i);
                formular = formular + "-" + S.substr(3 - i, 1);
            }
        }
        if (ans == 7) {
            cout << formular + "=7" << endl;
            break;
        }
    }
}
