#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<int>> field(h,vector<int>(w));
    rep(i,h)rep(j,w) cin >> field[i][j];
    int ct = 0;
    vector<vector<int>> ans;
    rep(i,h) {
        if (!(i&1)) {
            rep(j,w) {
                if (j != w-1) {
                    if (field[i][j]&1) {
                        ct++;
                        ans.push_back({i+1,j+1,i+1,j+2});
                        field[i][j]--;
                        field[i][j+1]++;
                    }
                }
                else {
                    if (field[i][j]&1 && i != h-1) {
                        ct++;
                        ans.push_back({i+1,j+1,i+2,j+1});
                        field[i][j]--;
                        field[i+1][j]++;
                    }
                }
            }
        }
        else {
            rep(j,w) {
                if (j != w-1) {
                    if (field[i][w-1-j]&1) {
                        ct++;
                        ans.push_back({i+1,w-j,i+1,w-1-j});
                        field[i][w-1-j]--;
                        field[i][w-2-j]++;
                    }
                }
                else {
                    if (field[i][w-1-j]&1 && i != h-1) {
                        ct++;
                        ans.push_back({i+1,w-j,i+2,w-j});
                        field[i][w-1-j]--;
                        field[i+1][w-1-j]++;
                    }
                }
            }
        }
    }
    cout << ct << endl;
    rep(i,ct) {
        rep(j,4) {
            if (j != 3) cout << ans[i][j] << " ";
            else cout << ans[i][j] << endl;
        }
    }
}