#include <bits/stdc++.h>
using namespace std;
int main () {
    string s = "";
    for (int i = 0; i < 4; i++) {
        int n;
        cin >> n;
        s += to_string(n);
    }
    sort(s.begin(), s.end());
    if (s == "1479") {
        puts("YES");
    }
    else {
        puts("NO");
    }
}