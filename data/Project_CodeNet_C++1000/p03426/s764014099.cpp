#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i, N) for (int i = 0; i < (int)(N); i++)

// chmax, chmin
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using P = pair<int,int>;

int main() {
    int H,W,D;
    cin >> H >> W >> D;
    
    map<int,P> m;
    REP(x,H)REP(y,W){
        int a;
        cin >> a;
        m[a] = make_pair(x,y);
    }
    int Q;
    cin >> Q;
    
    vector<ll> d(90010,0);
    for ( int i = D; i < 90010; ++i){
        P pb = m[i-D], p = m[i];
        int xb = pb.first, yb = pb.second, x = p.first, y = p.second;
        d[i] = d[i-D] + abs(x-xb) + abs(y-yb);
    }
    
    REP(i,Q){
        int l,r;
        cin >> l >> r;
        ll cost = d[r] - d[l];
        cout << cost << endl;
    }
    
    return 0;
}