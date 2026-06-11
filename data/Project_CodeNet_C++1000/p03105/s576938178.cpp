#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int a, b, c;

int main() {
    cin >> a >> b >> c;
    int cnt = b/a;
    if(cnt < c) cout << cnt << endl;
    else cout << c << endl;
}