#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int px[90005], py[90005], cost[90005];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int h, w, d, a;
    cin >> h >> w >> d;
    rep(i,h)rep(j,w){
        cin >> a;
        px[a] = i;
        py[a] = j;
    }
    for(int i = d+1; i <= h*w; i++){
        cost[i] = cost[i-d] + abs(px[i]-px[i-d]) + abs(py[i]-py[i-d]);
    }
    int q, l, r;
    cin >> q;
    rep(i,q){
        cin >> l >> r;
        cout << cost[r] - cost[l] << endl;
    }
    return 0;
}