#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<int>> V(H, vector<int> (W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
         cin >> V.at(i).at(j);
        }
    }
    
    vector<tuple<int, int, int, int>> ans;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W - 1; j++) {
        if (V.at(i).at(j) % 2 == 0) continue;
            V.at(i).at(j)--;
            V.at(i).at(j + 1)++;
            ans.push_back(make_tuple(i + 1, j + 1, i + 1, j + 2));
        }
    }
    
    for (int i = 0; i < H - 1; i++) {
        if (V.at(i).at(W - 1) % 2 == 0) continue;
        V.at(i).at(W - 1)--;
        V.at(i + 1).at(W - 1)++;
        ans.push_back(make_tuple(i + 1, W, i + 2, W));
    }
    
    cout << ans.size() << "\n";
    for (auto a : ans) {
        int a1, a2, a3, a4;
        tie(a1, a2, a3, a4) = a;
        cout << a1 << " " << a2 << " " << a3 << " " << a4 << "\n";
    }
}