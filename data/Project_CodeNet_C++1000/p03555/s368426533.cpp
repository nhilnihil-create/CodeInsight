#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1LL << 60;
const int MAX = 1000000010;
const ll MOD = 1000000007;

int main() {
    string s, t; cin >> s >> t;
    reverse(t.begin(), t.end());
    if (s == t) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}