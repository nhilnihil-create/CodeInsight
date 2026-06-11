#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;

    int len = 0, max_len = 0;
    for (char c : s) {
        switch (c) {
            case 'A':
            case 'C':
            case 'G':
            case 'T':
                len++;
                break;
            default:
                max_len = max(max_len, len);
                len = 0;
        }
    }

    cout << max(max_len, len) << endl;
}