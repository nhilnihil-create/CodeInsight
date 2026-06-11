#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
#define INF 1007654321
#define PI 3.14159265358979
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repp(i, s, e) for(int i = (s); i <= (e); ++i)
#define sz(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define FAST_IO() ios::sync_with_stdio(0); cin.tie(0)
template<typename T>
ostream& operator<<(ostream &os, const vector<T> &v) { for (auto x : v) os << x << " "; return os << "\n"; }

struct Point {
    ll x, y;
};

void print(int x, int y, int m) {
    if(m <= 0) {
        cout << "\n";
        return;
    }
    if(y + x >= 0 && y - x >= 0) {
        cout << 'U';
        print(x, y - (1LL << (m - 1)), m - 1);
    } else if(y + x >= 0 && y - x < 0) {
        cout << 'R';
        print(x - (1LL << (m - 1)), y, m - 1);
    } else if(y + x < 0 && y - x >= 0) {
        cout << 'L';
        print(x + (1LL << (m - 1)), y, m - 1);
    } else {
        cout << 'D';
        print(x, y + (1LL << (m - 1)), m - 1);
    }
}

int main() {
    FAST_IO();
    int N; cin >> N;
    vector<Point> P(N);
    rep(i, N) cin >> P[i].x >> P[i].y;
    bool hasOdd = false, hasEven = false;
    rep(i, N) {
        if((abs(P[i].x) + abs(P[i].y)) % 2 == 0) hasEven = true;
        else hasOdd = true;
    }
    if(hasOdd && hasEven) {
        cout << "-1\n";
        return 0;
    }
    if(hasEven) {
        rep(i, N) P[i].x -= 1;
    }
    const int m = 32;
    if(hasEven) {
        cout << m + 1 << "\n";
        cout << 1 << " ";
    }
    else cout << m << "\n";
    rep(i, m) {
        cout << (1LL << (m - i - 1)) << " ";
    }
    cout << "\n";
    rep(i, N) {
        if(hasEven) cout << 'R';
        print(P[i].x, P[i].y, m);
    }
}