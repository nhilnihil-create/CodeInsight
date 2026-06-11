#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e18;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int H,W,N;
    cin >> H >> W >> N;
    int r,c;
    cin >> r >> c;
    string S,T;
    cin >> S >> T;
    int x = r;
    for(int i = 0; i < N; i++) {
        if(S[i] == 'U') {
            x--;
        }
        if(x == 0) {
            cout << "NO" << endl;
            return 0;
        }
        if(T[i] == 'D') {
            if(x < H) {
                x++;
            }
        }
    }
    x = r;
    for(int i = 0; i < N; i++) {
        if(S[i] == 'D') {
            x++;
        }
        if(x > H) {
            cout << "NO" << endl;
            return 0;
        }
        if(T[i] == 'U') {
            if(x-1) {
                x--;
            }
        }
    }
    int y = c;
    for(int i = 0; i < N; i++) {
        if(S[i] == 'L') {
            y--;
        }
        if(y == 0) {
            cout << "NO" << endl;
            return 0;
        }
        if(T[i] == 'R') {
            if(y < W) {
                y++;
            }
        }
    }
    y = c;
    for(int i = 0; i < N; i++) {
        if(S[i] == 'R') {
            y++;
        }
        if(y > W) {
            cout << "NO" << endl;
            return 0;
        }
        if(T[i] == 'L') {
            if(y-1){
                y--;
            }
        }
    }
    cout << "YES" << endl;
}
