#include <bits/stdc++.h>
using namespace std;

int main() {
    string S; cin >> S;
    int cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < S.size(); i++) {
        if (S.at(i) == '0') cnt0++;
        else cnt1++;
    }
    if (cnt0 == cnt1) cout << S.size() << endl;
    else if (cnt0 > cnt1) cout << 2 * cnt1 << endl;
    else cout << 2 * cnt0 << endl;
}