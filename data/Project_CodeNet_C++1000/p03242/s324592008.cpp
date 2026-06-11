#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1LL << 60;
const int MAX = 100010;

int main() {
    string s; cin >> s;
    for (int i = 0; i < 3; i++) {
        if (s[i] == '1') {
            s[i] = '9';
        } else if (s[i] == '9') {
            s[i] = '1';
        }
    }
    cout << s << endl;
    return 0;
}