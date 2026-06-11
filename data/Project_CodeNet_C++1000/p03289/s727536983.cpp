#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string s;
    cin >> s;

    if (s.front() != 'A') {
        puts("WA");
        return 0;
    }

    int pos;
    int cnt = 0;
    for (int i = 2; i < s.size() - 1; i++) {
        if (s[i] == 'C') {
            pos = i;
            cnt++;
        }
    }
    if (cnt != 1) {
        puts("WA");
        return 0;
    }

    for (int i = 1; i < s.size(); i++) {
        if (i == pos) continue;
        if (isupper(s[i])) {
            puts("WA");
            return 0;
        }
    }
    puts("AC");
}
