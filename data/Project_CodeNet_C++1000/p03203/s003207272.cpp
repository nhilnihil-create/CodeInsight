#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int H, W, N;
    cin >> H >> W >> N;
    vector<set<int>>obs(H+1);
    for (int i = 0; i < N; ++i) {
        int x, y;
        cin >> x >> y;
        obs[x].insert(y);
    }

    // 高橋君がx=iで詰んだら答えはi
    // 左から見ていって各xごとに移動可能なyの値を更新する
    int ans = -1;
    int yb = 1;
    for (int i = 1; i < H; ++i) {
        if(obs[i+1].size() == 0 || *obs[i+1].begin() > yb+1){
            yb++;
        } else if(*obs[i+1].begin() <= yb){
            ans = i;
            break;
        }
    }
    if(ans == -1) ans = H;
    cout << ans << "\n";
    return 0;
}