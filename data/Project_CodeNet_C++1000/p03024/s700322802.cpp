#include <bits/stdc++.h>
using namespace std;
int main () {
    string s;
    int a = 0;
    cin >> s;
    for (auto c: s) {
        if (c == 'x') a++;
    }
    if (a <= 7) {
        puts("YES");
    }
    else {
        puts("NO");
    }
}