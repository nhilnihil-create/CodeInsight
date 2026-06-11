#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(ll i = (a); i < (b); ++i)
#define REP(i, n) for(ll i = 0; i < (n); ++i)
#define ARRAY_LENGTH(array) sizeof(array)/sizeof(*array)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
const int INF = 1000100100;

int main() {
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    ll dx12 = x2 - x1, dy12 = y2 - y1;
    ll x3, y3, x4, y4;
    if(abs(dx12) <= abs(dy12)) {
        x3 = x2 - dy12;
        y3 = y2 + dx12; 
    } else {
        x3 = x2 - dy12;
        y3 = y2 + dx12;
    }
    x4 = x3 - dx12;
    y4 = y3 - dy12;

    cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;

    return 0;
}