#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1LL << 60;

int main() {
    int a, b, x; cin >> a >> b >> x;
    string ans;
    if (x < a) {
        ans = "NO";
    } else if (x > a + b) {
        ans = "NO";
    } else {
        ans = "YES";
    }
    cout << ans << endl;
    return 0;
}