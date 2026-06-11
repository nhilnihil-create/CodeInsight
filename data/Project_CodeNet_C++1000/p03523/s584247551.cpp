#include <bits/stdc++.h>

using namespace std;


int main() {
    string s;
    cin >> s;
    if(s.size() > 9) {
        puts("NO");
        return 0;
    }
    for(int i = 0; i < s.size()- 1; i++) {
        if(s[i] == s[i+1]) {
            puts("NO");
            return 0;
        }
    }
    string x = "";
    for(int i = 0; i < s.size(); i++) {
        if(s[i] != 'A') {
            x += s[i];
        }
    }
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == 'K') {
            if(s[i+1] != 'I') {
                puts("NO");
                return 0;
            }
        }
        if(s[i] == 'I') {
            if(s[i+1] != 'H') {
                puts("NO");
                return 0;
            }
        }
    }
    if(x == "KIHBR") {
        puts("YES");
    } else {
        puts("NO");
    }
    return 0;
}