#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1LL << 60;

int main() {
    int a, b, c, d; cin >> a >> b >> c >> d;
    string ans = "No";
    if  ((a < b && b < c) || (c < b && b < a)) {
        if ((abs(b - a) <= d) && (abs(b - c) <= d)) ans = "Yes";
    } else {
        if (abs(c - a) <= d) ans = "Yes";
    }
    cout << ans << endl;
    return 0;
}