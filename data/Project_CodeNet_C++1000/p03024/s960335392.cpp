#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int a = 15 - s.size();
    int cnt = count(s.begin(), s.end(), 'o');

    if (cnt + a >= 8) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
