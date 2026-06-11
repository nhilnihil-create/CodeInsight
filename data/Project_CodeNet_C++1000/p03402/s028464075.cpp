#pragma region template
#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD = 1e9 + 7, MAX = LLONG_MAX, larg = 1e5, INF = -1e9;
long long A, B, C, D, E, F, G, H, I, J, K, L, N, M, O, P, Q, R, S, T, U, V, W;
typedef long long ll;
typedef pair<ll, ll> Pa;

char char_map[100][100];
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int main() {
    cin >> B >> A;
    rep(i, 50){
        rep(j, 100){
            char_map[i][j] = '.';
            char_map[i+50][j] = '#';
        }
    }
    int curr_x = 0, curr_y = 0;
    while(A > 1){
        bool flag = true;
        rep(i, 8){
            int x = curr_x + dx[i], y = curr_y + dy[i];
            if(x < 0 || 99 < x || y < 0 || 99 < y) continue;
            flag &= (char_map[y][x] == '.'); 
        }
        if(flag){
            char_map[curr_y][curr_x] = '#';
            A--;
        }
        curr_x++;
        if(curr_x == 100){
            curr_x = 0;
            curr_y++;
        }
    }

    curr_x = 99, curr_y = 99;
    while(B > 1){
        bool flag = true;
        rep(i, 8){
            int x = curr_x + dx[i], y = curr_y + dy[i];
            if(x < 0 || 99 < x || y < 0 || 99 < y) continue;
            flag &= (char_map[y][x] == '#'); 
        }
        if(flag){
            char_map[curr_y][curr_x] = '.';
            B--;
        }
        curr_x--;
        if(curr_x == -1){
            curr_x = 99;
            curr_y--;
        }
    }

    cout << 100 << " " << 100 << endl;
    rep(i, 100){
        rep(j, 100){
            cout << char_map[i][j];
        }
        cout << endl;
    }
}
