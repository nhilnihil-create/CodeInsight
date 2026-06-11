#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<P, P> PP;
const ll INF = 100000000;
#define rep1(i, n) for (ll i=0; i<(n); i++) 
#define rep2(i, k, n) for (ll i=k; i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
    ll h, w;
    cin >> h >> w;
    vector<vector<ll> > a(h, vector<ll>(w, 0));
    ll odd = 0;
    rep1(i, h) rep1(j, w) {
            cin >> a[i][j];
            if (a[i][j] & 1) odd++;
    }
    vector<PP> res;
    ll num = 0;
    ll x = 0, y = 0;
    rep1(i, w*h){
        if (a[x][y] & 1) num++;

        ll nx = x, ny = y;
        if (x % 2 == 0) {
            if (ny == w-1) nx++;
            else ny++;
        }
        else {
            if (ny == 0) nx++;
            else ny--;
        }
        if (num & 1) if (num < odd) res.push_back(PP(P(x, y), P(nx, ny)));
        x = nx, y = ny;
    }
    
    cout << res.size() << endl;
    for (auto p: res) {
        cout << p.first.first+1 << " " << p.first.second+1 << " " << p.second.first+1 << " " << p.second.second+1 << endl;
    }
    //printf("%.12f", ans);
}