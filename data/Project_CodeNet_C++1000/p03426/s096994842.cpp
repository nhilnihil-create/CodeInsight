#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = INT_MAX>>2;
vector<int> dist;
vector<pair<int,int>> a_inv;
int h,w,d;
int calc_dist(int l) {
    if(l < d) return 0; 
    if(dist[l] != INF) return dist[l];
    int x = a_inv[l].first;
    int y = a_inv[l].second;
    int nx = a_inv[l-d].first;
    int ny = a_inv[l-d].second;
    return dist[l] = calc_dist(l-d) + abs(x-nx) + abs(y-ny);
}
int main(){
    ios::sync_with_stdio(false);
    cin >> h >> w >> d;
    vector<vector<int>> a(h,vector<int>(w));
    a_inv.resize(h*w);
    dist.assign(h*w, INF);
    rep(y,h) rep (x,w) {
        cin >> a[y][x];
        a[y][x]--;
        a_inv[a[y][x]] = make_pair(x,y);
    }
    int q;
    cin >> q;
    rep(i,q) {
        int l,r;
        cin >> l >> r;
        l--;r--;
        cout << calc_dist(r) - calc_dist(l) << endl;
    }
}