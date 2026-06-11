#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

string s;
int main() {
    cin >> s;
    int ans = 0;
    for(int i = 0; i < s.length(); ++i) {
        if(s.at(i) == '+') ans++;
        else ans--;
    }
    cout << ans << endl;
}