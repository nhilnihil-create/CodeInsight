#include <bits/stdc++.h>

using namespace std;


int main() {
    string s;
    cin >> s;
    int n = s.size();
    bool ok = false;
    for(int i = 0; i < n; i++) {
        string x = "";
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                if(i <= k && k <= j) {
                    continue;
                } else {
                    x += s[k];
                }
            }
            if(x == "keyence") {
                ok = true;
            }
            x = "";
        }
    }
    if(ok) {
        puts("YES");
    } else {
        puts("NO");
    }
    return 0;
}