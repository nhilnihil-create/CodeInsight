#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
/* function */
/* main */
int main(){
    int H, W;
    cin >> H >> W;
    vector<vector<int> > v(H, vector<int>(W));
    for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) cin >> v[i][j];

    vector<vector<int> > t;
    for (int i = 0; i < H; i++) for (int j = 0; j < W - 1; j++) {
        if (v[i][j] % 2 == 1) {
            t.push_back({i+1, j+1, i+1, j+2});
            //cout << i+1 << ' ' << j+1 << ' ' << i+1 << ' ' << j+2 << '\n';
            v[i][j+1]++;
        }
    }

    for (int i = 0; i < H - 1; i++) {
        if (v[i][W-1] % 2 == 1) {
            t.push_back({i+1, W, i+2, W});
            // cout << i+1 << ' ' << W << ' ' << i+2 << ' ' << W << '\n';
            v[i+1][W-1]++;
        }
    }
    cout << t.size() << '\n';
    for (int i = 0; i < t.size(); i++) {
        for (int j = 0; j < 4; j++) {
            cout << t[i][j];
            cout << ((j == 3) ? '\n' : ' ');
        }
    }
}
