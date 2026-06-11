#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
int main(){
    ios::sync_with_stdio(false);
    int h,w;
    cin >> h >> w;
    vector<vector<int>> a(h,vector<int>(w));
    rep(i,h) rep(j,w) {
        cin >> a[i][j];
    }
    int state = 0;
    int pre_x = 0;
    int pre_y = 0;
    if(a[0][0]%2 == 0) state = 0;
    else state = 1;
    vector<vector<int>> ans; 
    rep(i,h) rep(j,w) {
        if(i==0 && j == 0) continue;
        int y = i;
        int x = j;
        if(y%2 == 1) x = w-1-j;
        if(state == 1) {
            ans.push_back({pre_y+1, pre_x+1, y+1,x+1});
            if(a[y][x]%2 == 1) state = 0;
        } else if(a[y][x]%2 == 1) state = 1;
        pre_x = x;
        pre_y = y;
    }
    cout << ans.size() << endl;
    for(auto i :ans) {
        rep(j,4) {
            cout << i[j];
            if(j != 3) cout <<" ";
            else cout << endl;
        }
    }
}
