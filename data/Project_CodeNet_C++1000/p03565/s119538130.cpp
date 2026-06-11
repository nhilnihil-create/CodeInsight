#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    string s, t; cin >> s >> t;
    int n = s.size(), m = t.size();
    string ans = {127}, c = {127};

    for(int i = 0; i < n; i++) {
        if(i + m > n)continue;
        string nxt = s;
        bool res = true;
        for(int j = 0; j < m; j++) {
            if(s[i + j] != t[j] && s[i + j] != '?')res = false;
            else if(s[i + j] != t[j])nxt[i + j] = t[j];
        }
        if(!res)continue;
        for(auto &i: nxt)if(i == '?')i = 'a';
        ans = min(ans, nxt);
    }
    cout << (ans == c ? "UNRESTORABLE" : ans) << endl;
}