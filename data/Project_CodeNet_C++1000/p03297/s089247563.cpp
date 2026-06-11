#include <bits/stdc++.h>
using namespace std;
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}
void print() { cout << "\n"; }
template <class T> void print(const T &x) { cout << x << "\n"; }
template <class T, class... Args> void print(const T &x, const Args &... args) {
    cout << x << " ";
    print(args...);
}
template <class T> void printVector(const vector<T> &v) {
    for(const T &x : v) {
        cout << x << " ";
    }
    cout << "\n";
}
using ll = long long;

#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
const double EPS = 1e-7;
const int INF = 1 << 30;
const ll LLINF = 1LL << 60;
const double PI = acos(-1);
constexpr int MOD = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

//-------------------------------------

ll GCD(ll a, ll b) {
    if(b == 0)
        return a;
    else
        return GCD(b, a % b);
}

ll LCM(ll a, ll b) { return a * b / GCD(a, b); }

void solve() {
    ll A, B, C, D;
    cin >> A >> B >> C >> D;
    if(A < B || D < B) {
        print("No");
        return;
    }
    if(C + 1 - B >= 0) {
        print("Yes");
        return;
    }
    ll g = GCD(B, D);
    ll l = (C - A) / g;
    ll r = (B - A) / g;
    if(C - A < 0 && (A - C) % g != 0) {
        l--;
    }
    // print(l, r, g);
    print((r - l >= 2) ? "No" : "Yes");
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}