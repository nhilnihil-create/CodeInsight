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
using namespace std;

int mx8[] = {0,0,1,-1,-1,1,-1,1};
int my8[] = {-1,1,0,0,-1,-1,1,1};


int main() {
    int h, w;
    cin >> h >> w;
    char g[h + 2][w + 2];
    rep(i, h + 2) rep(j, w + 2) g[i][j] = '/';
    for (int i = 1; i < h + 1; i++)
        for (int j = 1; j < w + 1; j++) {
            cin >> g[i][j];
        }

    for (int i = 1; i < h + 1; i++) {
        for (int j = 1; j < w + 1; j++) {
            int cnt = 0;
            rep(k,8){
                if(g[i+my8[k]][j+mx8[k]] == '#'){
                    cnt++;
                }
            }
            if(g[i][j] == '#') cout << '#';
            else cout << cnt;
        }
        cout << endl;
    }
}
