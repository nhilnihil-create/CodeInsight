#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
    int R;
    cin >> R;
    if(R < 1200) cout << "ABC" << endl;
    else if (R< 2800) cout << "ARC" << endl;
    else cout << "AGC" << endl;
}