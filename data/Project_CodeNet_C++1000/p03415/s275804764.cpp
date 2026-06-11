#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1LL << 60;
const ll MOD = 1000000007;

int main() {
    vector<string> c(3);
    for (int i = 0; i < 3; i++) {
        cin >> c[i];
    }

    string ans = "";
    ans += c[0][0];
    ans += c[1][1];
    ans += c[2][2];
    cout << ans << endl;
    return 0;
}