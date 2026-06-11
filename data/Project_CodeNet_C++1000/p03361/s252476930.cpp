#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int H,W; char s[55][55];
void input()
{
    cin >> H >> W;
    for (int i = 0; i <= H+1; ++i){
        for (int j = 0; j <= W+1; ++j){
            s[i][j] = '.';
        }
    }
    for (int i = 1; i <= H; ++i){
        for (int j = 1; j <= W; ++j){
            cin >> s[i][j];
        }
    }
}

void solve()
{
    bool chk = true;
    for (int i = 1; i <= H; ++i){
        for (int j = 1; j <= W; ++j){
            if (s[i][j] == '.') continue;
            if (s[i-1][j] == '.' && s[i][j-1] == '.' 
            && s[i+1][j] == '.' && s[i][j+1] == '.') {
                chk = false; break;
            }
        }
    }

    if (chk) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    input();
    solve();
    return 0;
}