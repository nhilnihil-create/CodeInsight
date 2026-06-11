#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int H, W;
    cin >> H >> W;
    vector<int> x{1, 0, -1, 0};
    vector<int> y{0, 1, 0, -1};
    vector<vector<char> > m(H,vector<char>(W));
    for(int i = 0; i < H; i++) {
        string S;
        cin >> S;
        for(int j = 0; j < W; j++) {
            m.at(i).at(j) = S.at(j);
        }
    }
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(m.at(i).at(j) == '.') {
                continue;
            }
            int check = 0;
            for(int k = 0; k < 4; k++) {
                int nx = j + x.at(k);
                int ny = i + y.at(k);
                if(nx > -1 && ny > -1 && nx < W && ny < H) {
                    if(m.at(ny).at(nx) == '#') {
                        check = 1;
                    }
                }
            }
            if(check) {
                continue;
            } else {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;



    return 0;
}