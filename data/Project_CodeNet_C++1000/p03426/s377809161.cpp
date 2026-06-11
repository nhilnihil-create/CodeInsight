#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
using ll = long long;
using P = pair<int, int>;
ll GCD(ll a, ll b) { return b?GCD(b, a%b):a; }
ll LCM(ll a, ll b) { return a/GCD(a, b)*b; }

int h, w, d;
struct xydata {
    int x; int y;
};

ll xyabs(xydata const &aa, xydata const &bb) {
    ll nxy = abs(aa.x-bb.x) + abs(aa.y-bb.y);
    return nxy;
}

int main() {
    cin >> h >> w >> d;
    int limit = h*w;
    vector<xydata> Zxy(limit);
    vector<ll> Zsum(limit, 0);
    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {
            int A; cin >> A; A--;
            xydata indata; indata.x = j; indata.y = i;
            Zxy.at(A) = indata;
        }
    }

    for(int i = limit-1; i >= 0; --i) {
        if(i-d >= 0) {
            Zsum.at(i-d) = Zsum.at(i) + xyabs(Zxy.at(i), Zxy.at(i-d));
        }
    }

    int Q; cin >> Q;
    for(int i = 0; i < Q; ++i) {
        int l, r; cin >> l >> r;
        l--; r--;
        cout << Zsum.at(l) - Zsum.at(r) << endl;
    }
}