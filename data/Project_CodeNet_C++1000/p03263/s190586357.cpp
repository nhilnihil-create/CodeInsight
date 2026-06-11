#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int H,W;
    cin >> H >> W;
    vector<vector<int>>a(H,vector<int>(W));
    vector<vector<int>>ans(H*W,vector<int>(4));
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cin >> a[i][j];
        }
    }
    int X = 0;int Y = 0;int A = 0;int B = 0;
    int cnt = 0;
    while(X < H && Y < W) {
        bool ok = false;
        if(a[X][Y]%2 == 1) {
            ok = true;
            A = X; B = Y;
        }
        if(X%2 == 0) {
            if(Y+1 < W) {
                Y++;
            }
            else {
                X++;
            }
        }
        else {
            if(Y-1 >= 0) {
                Y--;
            }
            else {
                X++;
            }
        }
        if(ok && X < H) {
            a[X][Y]+=1;
            ans[cnt] = {A+1,B+1,X+1,Y+1};
            cnt++;
        }
    }
    cout << cnt << endl;
    for(int i = 0; i < cnt; i++) {
        for(int j = 0; j < 4; j++) {
            cout << ans[i][j];
            if(j+1 != 4) {
                cout << " ";
            }
        }
        cout << endl;
    }
}