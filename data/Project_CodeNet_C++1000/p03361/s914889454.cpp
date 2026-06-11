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
vector<int> dx{1, -1, 0, 0};
vector<int> dy{0, 0, 1, -1};
/* function */
/* main */
int main(){
    int H, W;
    cin >> H >> W;
    vector<string> pic(H);
    for (int i = 0; i < H; i++) cin >> pic[i];

    for (int x = 0; x < H; x++) {
        for (int y = 0; y < W; y++) {
            if (pic[x][y] == '.') continue;
            bool can = false;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || H <= nx || ny < 0 || W <= ny) continue;
                if (pic[nx][ny] == '#') can = true;
            }
            if (can == false) {
                cout << "No" << '\n';
                return 0;
            }
        }
    }

    cout << "Yes" << '\n';
}