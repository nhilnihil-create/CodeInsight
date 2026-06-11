
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string s;
int Cnt1, Cnt2;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    int n = s.length();
    // 1: 010101
    // 2: 101010
    for (int i = 0; i < n; ++i) {
        if (i & 1) {
            if (s[i] == '1') {
                ++Cnt2;
            } else {
                ++Cnt1;
            }
        } else {
            if (s[i] == '1') {
                ++Cnt1;
            } else {
                ++Cnt2;
            }
        }
    }
    cout << min(Cnt1, Cnt2) << endl;

    return 0;
}

