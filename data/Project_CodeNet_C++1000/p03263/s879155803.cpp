#include<bits/stdc++.h>
#define ll long long
#define ALL(v) (v).begin(),(v).end()
#define REP(i,p,n) for(int i=p;i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define dump(a) (cerr << #a << "=" << (a) << endl)
#define DUMP(list) cout << "{ "; for(auto nth : list){ cout << nth << " "; } cout << "}" << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }


using namespace std;

typedef pair<int, int> pint;
typedef pair<pint, pint> ppint;

int main(){

    int H, W;
    cin >> H >> W;

    vector<vector<int>> a(H, vector<int>(W, 0));
    int odd = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> a[i][j];
            if (a[i][j] & 1) ++odd;
        }
    }

    vector<ppint> res;
    int num = 0;
    int x = 0, y = 0;
    for (int iter = 0; iter < W*H; ++iter) {
        if (a[x][y] & 1) ++ num;

        int nx = x, ny = y;
        if (x % 2 == 0) {
            if (ny == W - 1) ++nx;
            else ++ny;
        } else {
            if (ny == 0) ++nx;
            else --ny;
        }
        if (num & 1) if (num < odd) res.push_back(ppint(pint(x, y), pint(nx, ny)));
        x = nx, y = ny;

    }

    cout << res.size() << endl;
    for (auto p: res) {
        cout << p.first.first + 1 << " " << p.first.second + 1 << " " << p.second.first+1 << " " << p.second.second+1 << endl;
    }



}
