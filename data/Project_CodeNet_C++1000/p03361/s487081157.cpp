#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii =  pair<int, int>;
using pll =  pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long INF = 1000000009LL;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int dx[4] = {-1 ,0 ,1 ,0};
const int dy[4] = {0, -1, 0, 1};

int main() {
    int H, W; cin >> H >> W;
    vector<vector<char>> grid(H+2, vector<char>(W+2, '.'));
    rep(i, H){
        string s; cin >> s;
        rep(j, W){
           grid[i+1][j+1] = s[j];
        }
    }
    
    bool fg = true;
    rep(i, H){
        rep(j, W){
            if(grid[i+1][j+1] == '.') continue;
            bool is_allWhite = true;
            rep(k, 4){
                int x = j+1 + dx[k];
                int y = i+1 + dy[k];
                if(grid[y][x] == '#'){
                    is_allWhite = false;
                    break;
                }
            }
            if(is_allWhite){ fg = false; break;}
        }
    }

    if(fg) cout << "Yes" << ln;
    else cout << "No" << ln;
}
