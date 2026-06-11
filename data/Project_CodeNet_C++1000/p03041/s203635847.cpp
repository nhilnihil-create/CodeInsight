#include <bits/stdc++.h>

using namespace std;

int main() {
    int n = 0, k = 0;
    cin >> n >> k;
    string s, ans;
    cin >> s;

    for (int i = 0; i < s.length(); ++i) {
        char c;
        c = s.at(i);
        if (i == k - 1) {
            c = tolower(c);
        }
        ans += c;
    }

    cout << ans << endl;
}