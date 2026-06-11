#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<vector<int>> Graph;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353

int main() {
    int H, W; cin >> H >> W;
    vector<string> S(H);
    for(int i = 0; i < H; i++) cin >> S[i];
    for(int h = 0; h < H; h++) for(int w = 0; w < W; w++) {
        if(S[h][w] != '#') {
            for(int i = h - 1; i <= h + 1; i++) for(int j = w - 1; j <= w + 1; j++) {
                if(i == h && j == w) continue;
                else if(i < 0 || j < 0 || i >= H || j >= W) continue;
                else {
                    if(S[i][j] == '#') {
                        if(S[h][w] == '.') S[h][w] = '1';
                        else {
                            
                            S[h][w]++;
                        }
                    }
                }
            }
        }
        if(S[h][w] == '.') S[h][w] = '0';
    }
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cout << S[i][j];
        }
        cout << endl;
    }
    return 0;
}