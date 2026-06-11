#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
int main(){
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    string s2;
    int i = 0;
    while(i < s.size()) {
        s2 = s2 + s[i];
        if(i != s.size()-1) {
            if(s[i] == 'B' && s[i+1] == 'C') {
                s2[s2.size()-1] = 'D';
                i++;
            }
        }
        i++;
    }
    int a_num = 0;
    ll ans = 0;
    rep(j,s2.size()) {
        if(s2[j] == 'A') a_num++;
        else if(s2[j] == 'D') ans += a_num;
        else a_num = 0;
    }
    cout << ans << endl;
}
