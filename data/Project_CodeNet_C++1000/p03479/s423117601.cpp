#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1LL << 60;

int main() {
    ll x, y; cin >> x >> y;
    int cnt = 0;
    while (x <= y) {
        x *= 2;
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}