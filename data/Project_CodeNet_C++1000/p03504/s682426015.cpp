#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順
vector<vector<bool>> Chan;


int main() {
    int N, C; cin >> N >> C;
    Chan.assign(C, vector(100007, false));
    rep(i,N) {
        int s,t,c; cin >> s >> t >> c;
        s--,t--,c--;
        for(int j = s; j <= t; j++) Chan[c][j] = true;
    }
    int ma = 0;
    rep(i,100000) {
        int channel = 0;
        rep(j,C) {
            if (Chan[j][i]) channel++;
        }
        ma = max(ma, channel);
    }
    cout << ma << endl;
}
