#include <bits/stdc++.h>

using namespace std;


int main() {
    int n;
    cin >> n;
    vector<string> w(n);
    for(int i = 0; i < n; i++) {
        cin >> w[i];
    }
    bool ok = true;
    for(int i = 0; i < n-1; i++) {
        int sz = w[i].size();
        if(w[i][sz-1] != w[i+1][0]) {
            ok = false;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i != j && w[i] == w[j]) {
                ok = false;
            }
        }
    }
    if(ok) {
        puts("Yes");
    } else {
        puts("No");
    }
    return 0;
}