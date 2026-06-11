#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
using ll = long long;
using P = pair<int, int>;
ll GCD(ll a, ll b) { return b?GCD(b, a%b):a; }
ll LCM(ll a, ll b) { return a/GCD(a, b)*b; }


int main() {
    string s; cin >> s;
    int slen = s.length();
    bool flg = true;
    if(s.at(0) == '0' || s.at(slen-1) == '1') flg = false;
    for(int i = 0; i < slen/2; ++i) {
        if(s.at(i) != s.at(slen-2-i)) {
            flg = false;
            break;
        }
    }

    if(!flg) {
        cout << -1 << endl;
        return 0;
    }

    s.at(slen-1) = '1';
    queue<int> que;
    for(int i = 1; i <= slen; ++i) {
        if(s.at(i-1) == '1') que.push(i);
    }

    for(int i = 1; i < slen; ++i) {
        if(i == que.front()) que.pop();
        cout << i << " " << que.front() << endl;
    }
}