#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#define llong long long
#define INF (__INT32_MAX__ / 2)
#define MAX_N 200000

using namespace std;
typedef pair<int, int> ipair;

int H, W, N, x, y;
string S, T;

int cnt_S[4][MAX_N + 1], cnt_T[4][MAX_N + 1];
string chars = "LRUD";

//高橋君が勝つかどうかを返す
bool solve() {
    for(int i = 0; i < N; ++i) {
        bool to_left, to_up;
        //高橋君
        to_left = x + cnt_S[1][i] - cnt_T[0][i] - W < 
                         - (x - cnt_S[0][i] + cnt_T[1][i]);

        to_up = y + cnt_S[3][i] - cnt_T[2][i] - H < 
                         - (y - cnt_S[2][i] + cnt_T[3][i]);

        if(S[i] == 'L' && to_left) x--;
        if(S[i] == 'R' && !to_left) x++;
        if(S[i] == 'U' && to_up) y--;
        if(S[i] == 'D' && !to_up) y++;

        if(x < 0 || x >= W || y < 0 || y >= H) return false;

        //青木君
        to_left = x + cnt_S[1][i + 1] - cnt_T[0][i] - W < 
                         - (x - cnt_S[0][i + 1] + cnt_T[1][i]);

        to_up = y + cnt_S[3][i + 1] - cnt_T[2][i] - H < 
                         - (y - cnt_S[2][i + 1] + cnt_T[3][i]);

        if(T[i] == 'L' && !to_left) x--;
        if(T[i] == 'R' && to_left) x++;
        if(T[i] == 'U' && !to_up) y--;
        if(T[i] == 'D' && to_up) y++;

        if(x < 0 || x >= W || y < 0 || y >= H) return false;
    }

    return true;
}

int main(int argc, char **argv) {
    cin >> H >> W >> N >> y >> x;
    cin >> S >> T;
    y--, x--;

    cnt_S[0][N] = cnt_S[1][N] = cnt_S[2][N] = cnt_S[3][N] = 0;
    cnt_T[0][N] = cnt_T[1][N] = cnt_T[2][N] = cnt_T[3][N] = 0;

    for(int i = N - 1; i >= 0; --i)
        for(int j = 0; j < 4; ++j) {
            cnt_S[j][i] = cnt_S[j][i + 1] + (S[i] == chars[j]);
            cnt_T[j][i] = cnt_T[j][i + 1] + (T[i] == chars[j]);;
        }
    
    
    cout << (solve() ? "YES" : "NO") << endl;
}