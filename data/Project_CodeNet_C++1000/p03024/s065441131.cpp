#include <bits/stdc++.h>
using namespace std;

#define watch(x) cerr << (#x) << ": " << (x) << endl

int32_t main() {

    string s; cin >> s;
    int need = 8, rem = 15;
    for(char c : s) {
        if(c == 'o') need--;
        rem--;
    }

    if(rem >= need) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
