#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main() {
    int k, t = 0;
    string str, ans;
    cin >> str >> k;
    set<string> st;
    rep(i, str.length()) {
        rep(j, k) st.insert(str.substr(i, j + 1));
    }
    for(string temp : st) {
        t++;
        if(t == k) ans = temp;
    }
    cout << ans << endl;
}