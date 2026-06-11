#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    string s, t;
    cin >> s >> t;
    map<char, char> a, b;
    bool ok = true;
    rep(i, s.size()){
        if(a.count(s[i])) if(a[s[i]]!=t[i]) ok = false;
        if(b.count(t[i])) if(b[t[i]]!=s[i]) ok = false;
        a[s[i]] = t[i];
        b[t[i]] = s[i];
    }
    if(!ok) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}