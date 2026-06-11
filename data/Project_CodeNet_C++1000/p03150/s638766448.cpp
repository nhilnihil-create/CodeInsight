#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    string s;
    cin >> s;
    int sz = s.size();
    int remove_size = sz - 7;
    string ans = "NO";
    rep(i,8) {
        string lef = s.substr(0, i);
        string rig = s.substr(i+remove_size, sz-i-remove_size);
        if (lef + rig == "keyence") ans = "YES"; 
    }
    cout << ans << endl;
}