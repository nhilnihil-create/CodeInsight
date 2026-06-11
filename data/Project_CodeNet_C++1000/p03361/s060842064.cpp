#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {1, -1, 0, 0};

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    vector<vector<int>> cnt(h, vector<int>(w, 0));
    rep(i,h) cin >> s[i];
    rep(i,h){
        rep(j,w){
            if(s[i][j]=='.') continue;
            bool ok = false;
            rep(k,4){
                int nh = i + dx[k];
                int nw = j + dy[k];
                if(nh >= h || nh < 0 || nw >= w || nw < 0) continue;
                if(s[nh][nw]=='#' && s[i][j]=='#') ok = true;
            }
            if(!ok) {cout << "No" << endl; return 0;}
        }
    }
    cout << "Yes" << endl;
    return 0;
}