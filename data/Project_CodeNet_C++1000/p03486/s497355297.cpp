#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
    string s;
    string t;
    cin >> s;
    cin >> t;
    sort(all(s));
    sort(all(t));
    reverse(all(t));

    if (s < t)cout << "Yes" << endl;
    else cout << "No" << endl;
    
}