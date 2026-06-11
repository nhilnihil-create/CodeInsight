#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1LL << 60;

bool conditions(string &s) {
    if (s[0] != 'A') {
        return false;
    }
    s[0] = 'a';

    int n = s.length();
    int cnt = 0;
    for (int i = 2; i <= n - 2; i++) {
        if (s[i] == 'C') {
            cnt++;
            s[i] = 'c';
        }
    }
    if (cnt != 1) {
        return false;
    }

    for (int i = 0; i < n; i++) {
        if (isupper(s[i])) {
            return false;
        }
    }

    return true;
}

int main() {
    string s; cin >> s;
    if (conditions(s)) {
        cout << "AC" << endl;
    } else {
        cout << "WA" << endl;
    }
    return 0;
}