#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main(){
    int h, w, d; cin >> h >> w >> d;
    vector<vector<int>> a(h, vector<int>(w));
    vector<P> place(h*w+1); 
    rep(i,h)rep(j,w) {
        cin >> a[i][j];
        place[a[i][j]] = P(i,j);
    } 
    vector<int> mp(h*w+1, 0);
    for(int i = 1; i <= h*w; i++){
        if(i <= d) mp[i] = 0;
        else {
            int x1 = place[i].first;
            int y1 = place[i].second;
            int x2 = place[i-d].first;
            int y2 = place[i-d].second;
            mp[i] = mp[i-d] + abs(x1 - x2) + abs(y1 - y2);
        }
    }
    int q; cin >> q;
    rep(i,q){
        int l, r; cin >> l >> r;
        cout << mp[r] - mp[l] << endl;
    }
    return 0;
}