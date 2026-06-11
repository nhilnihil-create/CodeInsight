#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
//#define int long long
template<typename T> inline bool chmax(T& a,T b) { if (a < b) { a = b; return true; } return false; }
template<typename T> inline bool chmin(T& a,T b) { if (a > b) { a = b; return true; } return false; }

signed main() {
    int a, b;
    cin >> a >> b;
    cout << a + b/2 << endl;
    return 0;
}