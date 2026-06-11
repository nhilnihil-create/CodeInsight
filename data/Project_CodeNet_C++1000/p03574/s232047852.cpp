#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int H, W;
    cin >> H >> W;
    vector<int> x{1, 1, 1, 0, -1, -1, -1, 0};
    vector<int> y{-1, 0, 1, 1, 1, 0, -1, -1};
    vector<vector<char> > inp(H,vector<char>(W));
    vector<vector<int> > outp(H,vector<int>(W,0));

    for(int i = 0; i < H; i++) {
        string S;
        cin >> S;
        for(int j = 0; j < W; j++) {
            inp.at(i).at(j) = S.at(j);
            for(int k = 0; k < 8; k++) {
                int nx = j + x.at(k);
                int ny = i + y.at(k);
                if(nx >= 0 && ny >= 0 && nx < W && ny < H && inp.at(i).at(j) == '#') {
                    outp.at(ny).at(nx)++;
                }
            }
        }
    }
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(inp.at(i).at(j) == '.') {
                cout << outp.at(i).at(j);
            } else {
                cout << '#';
            }
        }
        cout << endl;
    }
    

    return 0;
}