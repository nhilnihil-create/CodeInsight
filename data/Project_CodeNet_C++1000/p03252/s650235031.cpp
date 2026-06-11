#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

string s, t;

int main() {
    cin >> s >> t;
    
    bool flg = true;
    vector<char> salp(26, '.');
    vector<char> talp(26, '.');
    for(int i = 0; i < s.length(); ++i) {
        char ss = s.at(i); char tt = t.at(i);
        int sint = ss - 'a';
        int tint = tt - 'a';

        if(salp.at(sint) != '.' || talp.at(tint) != '.') {
            // cout << "s " << salp.at(sint) << " t " << talp.at(tint) << endl;
            if(salp.at(sint) != tt || talp.at(tint) != ss) {
                flg = false;
                break;
            }
        }
        salp.at(sint) = tt;
        talp.at(tint) = ss;
    }

    if(flg) cout << "Yes" << endl;
    else cout << "No" << endl;
}