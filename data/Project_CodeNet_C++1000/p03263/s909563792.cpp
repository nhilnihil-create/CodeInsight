#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int H,W;
    cin >> H >> W;
    vector<vector<int>>a(H,vector<int>(W));
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cin >> a[i][j];
        }
    }
    vector<pair<P,P>>ans;
    int nx = 0,ny = 0;
    while(true) {
        int ox = nx,oy = ny;
        bool ok = false;
        if(a[nx][ny]%2 == 1) {
            ok = true;
        }
        if(nx%2 == 0) {
            if(ny+1 == W) {
                nx++;
            }
            else {
                ny++;
            }
        }
        else {
            if(ny-1 == -1) {
                nx++;
            }
            else {
                ny--;
            }
        }
        if(nx == H) {
            break;
        }
        if(ok) {
            ans.push_back({{ox+1,oy+1},{nx+1,ny+1}});
            a[nx][ny]++;
        }
    }
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i].first.first << " " << ans[i].first.second << " " << ans[i].second.first << " " << ans[i].second.second << endl;
    }
}