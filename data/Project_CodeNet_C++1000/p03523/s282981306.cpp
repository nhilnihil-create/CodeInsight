#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s;
    cin >> s;
    string e = "AKIHABARA";
    for (int i = 0; i < e.size(); i++) {
        if (s.size() < i) break;
        if (s.size() == i){
            if (e[i] == 'A') s.push_back('A');
            break;
        } 
        // i < s.size() 
        if (s[i] != e[i] && e[i] == 'A') {
            s.insert(i, "A");
        }
    }
    cout << (s == e ? "YES" : "NO") << endl;
    return 0;
}