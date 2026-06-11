#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#define ll long long int
#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
using namespace std;

int mx8[] = {0,0,1,-1,-1,1,-1,1};
int my8[] = {-1,1,0,0,-1,-1,1,1};
int mx4[] = {1,-1,0,0};
int my4[] = {0,0,-1,1};



int main() {
    int h, w;
    cin >> h >> w;
    char grid[h + 2][w + 2];
    rep(i, h + 2) rep(j, w + 2) grid[i][j] = '/';
    REP(i, h) REP(j, w) cin >> grid[i][j];

    bool ok = true;
    REP(i, h) REP(j, w) {
            if (grid[i][j] == '#') {
                bool flag = false;
                rep(k, 4) {
                    if (grid[i + my4[k]][j + mx4[k]] == '#') {
                        flag = true;
                    }
                }
                if (!flag) ok = false;
            }
        }
    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;
}
