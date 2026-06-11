#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    bool state = 0;
    long c1 = 0;
    long c2 = 0;
    for (auto i : s) {
        if (i=='0' && state) c1++;
        if (i=='1' && !state) c1++;
        state = !state;
    }
    state = 1;
    for (auto i : s) {
        if (i=='0' && state) c2++;
        if (i=='1' && !state) c2++;
        state = !state;
    }
    cout << min(c1,c2);
    return 0;
}