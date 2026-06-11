#include <bits/stdc++.h>
using namespace std;
 
using ll=long long;
 
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define pb push_back
#define eb emplace_back
#define a first
#define b second
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
const ll MOD = 1e9 + 7;

int main() {
    string s;
    cin >> s;
    string alts = "";
    int n = s.size();
    bool block = false;
    rep(i, n) {
        if (s[i] == 'A') {
            alts.push_back('a');
            block = false; 
        } 
        else {
            if (!block && i < n - 1 && s[i] == 'B' && s[i+1] == 'C') {
                alts.push_back('x');
                ++i; 
            } else {
                if(!block) alts.push_back('b');
                block = true;
            }

        }
    }
    ll cnta = 0, ans = 0; 
    for (char c : alts) {
        if (c == 'a') ++cnta;
        else if (c == 'x') ans += cnta;
        else cnta = 0; 
    }
    cout << ans << endl;
    return 0;
}