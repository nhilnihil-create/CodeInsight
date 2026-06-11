#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1LL << 60;
const int MAX = 100010;

int main() {
    int k; cin >> k;
    int ans;
    if (k % 2 == 1) {
        ans = (k / 2) * ((k + 1) / 2);
    } else {
        ans = pow(k / 2, 2);
    }
    cout << ans << endl;
    return 0;
}