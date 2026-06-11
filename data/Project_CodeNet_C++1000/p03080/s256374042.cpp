#include <bits/stdc++.h>
using namespace std;
int main () {
    char c;
    map<char, int> m;
    while (cin >> c) {
        m[c]++;
    }
    if (m['R'] > m['B']){
        puts("Yes");
    }
    else puts("No");
}