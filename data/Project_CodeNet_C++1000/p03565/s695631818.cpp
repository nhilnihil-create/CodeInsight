#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
using ll = long long;
using P = pair<int, int>;
ll GCD(ll a, ll b) { return b?GCD(b, a%b):a; }
ll LCM(ll a, ll b) { return a/GCD(a, b)*b; }


int main() {
    string s, t;
    cin >> s >> t;
    bool flg = false;
    int slen = s.length(); int tlen = t.length();
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());
    for(int i = 0; i < slen; ++i) {
        bool flg2 = true;
        for(int j = 0; j < tlen; ++j) {
            if(i+j < slen && s.at(i+j) == '?') {

            }else {
                if(i+j < slen && s.at(i+j) == t.at(j)) {
                    
                }else {
                    flg2 = false; break;
                }
            }
        }
        if(flg2) {
            flg = true;
            for(int j = 0; j < tlen; ++j) {
                s.at(i+j) = t.at(j);
            }
            break;
        }
    }
    if(!flg) cout << "UNRESTORABLE" << endl;
    else {
        for(int i = 0; i < slen; ++i) {
            if(s.at(i) == '?') s.at(i) = 'a';
        }
        reverse(s.begin(), s.end());
        cout << s << endl;
    }
}