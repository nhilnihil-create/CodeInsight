#include <bits/stdc++.h>

using namespace std;


int main() {
    string s;
    cin >> s;

    int temp = 0, maxL = 0;
    for (int i = 0; i <= s.length(); i++) {
        if (s[i] == 'A' || s[i] == 'C' || s[i] == 'G' || s[i] == 'T') {
            temp++;
        } else {
            if (temp >= maxL) {
                maxL = temp;
                temp = 0;
            } else {
                temp = 0;
            }
        }
    }

    cout << maxL << endl;
}
