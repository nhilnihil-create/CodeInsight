#include <bits/stdc++.h>

using namespace std;


int main() {
    string s;
    cin >> s;
    int counter = 0;
    int n = s.size();
    for(int i = 0; i < n; i++) {
        if(s[i] == 'o') {
            counter++;
        }
    }
    int rest = 15- n;
    counter += rest;
    if(counter >= 8) {
        puts("YES");
    } else {
        puts("NO");
    }
    return 0;
}