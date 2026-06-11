#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
    string s1;
    string s2;
    cin >> s1;
    cin >> s2;
    if (s1[0] == s2[2] && s1[1] == s2[1] && s1[2] == s2[0])cout << "YES" << endl;
    else cout << "NO" << endl; 
}