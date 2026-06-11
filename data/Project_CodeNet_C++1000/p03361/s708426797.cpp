#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int H,W;
    cin >> H >> W;
    vector<vector<char>>s(H+2,vector<char>(W+2,'.'));
    for(int i = 1; i <= H; i++) {
        for(int j = 1; j <= W; j++) {
            char x;
            cin >> x;
            s[i][j] = x;
        }
    }
    for(int i = 1; i <= H; i++) {
        for(int j = 1; j <= W; j++) {
            if(s[i][j] == '.') {
                continue;
            }
            if(s[i-1][j] != '#' && s[i+1][j] != '#' &&
               s[i][j-1] != '#' && s[i][j+1] != '#') {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
}

