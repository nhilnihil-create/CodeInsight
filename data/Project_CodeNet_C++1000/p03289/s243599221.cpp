#include <bits/stdc++.h>

using namespace std;


int main() {
    string s;
    cin >> s;
    int n = s.size();
    bool ok = true;
    if(s[0] != 'A') {
        ok = false;
    }
    int counter = 0;
    for(int i = 2; i <= n-2; i++) {
        if(s[i] == 'C') {
            counter++;
        }
    }
    if(counter != 1) {
        ok = false;
    }
    if(!ok) {
        puts("WA");
        return 0;
    }
    for(int i = 0; i < n; i++) {
        if(s[i] != 'A' && s[i] != 'C') {
            if(s[i] < 97) {
                ok = false;
            }
        }
    }
    if(ok) {
        puts("AC");
    } else {
        puts("WA");
    }
    return 0;
}