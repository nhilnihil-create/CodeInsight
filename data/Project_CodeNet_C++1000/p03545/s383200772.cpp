#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    string str;
    int n = 3;
    int cnt = 0;
    cin >> str;

    vector<int> vec(4);

    for (int i = 0; i < 4; i++) vec.at(i) = str.at(i) - '0';

    for (int bit = 0; bit < (1 << n); bit++) {
        int calc = vec.at(0);
        string str = to_string(vec.at(0));

        for (int i = 0; i < n; i++) {
            if (bit & (1 << i)) {
                calc += vec.at(i + 1);
                str +=  "+" + to_string(vec.at(i + 1));
            } else {
                calc -= vec.at(i + 1);
                str += "-" + to_string(vec.at(i + 1));
            }
        }

        if (calc == 7) {
            cout << str + "=7";
            return 0;
        }
    }
    //
}
