#include <bits/stdc++.h>

using namespace std;


int main() {
    map<int,int> m;
    for(int i = 0; i < 3; i++) {
        int a,b;
        cin >> a >> b;
        m[a]++;
        m[b]++;
    }
    bool ok = true;
    for(auto c : m) {
        if(c.second == 3) {
            ok = false;
        } 
    }
    if(ok) {
        puts("YES"); 
    } else {
        puts("NO");
    }
    return 0;
}