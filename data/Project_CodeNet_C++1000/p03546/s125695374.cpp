#define _GLIBCXX_DEBUG //配列の略記用
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int main(){
    int H, W;
    cin >> H >> W;
    
    const int INF = 1e8;
    vector<vector<int>> cost(10, vector<int>(10, INF));
    rep(i, 10){
        rep(j, 10){
            cin >> cost[i][j];
        }
    }

    rep(k, 10){
        rep(i, 10){
            rep(j, 10){
                cost[i][j] = min(cost[i][j], cost[i][k]+cost[k][j]);
            }
        }
    }

    int ans = 0;

    rep(i, H){
        rep(j, W){
            int wall;
            cin >> wall;
            if (wall == -1 || wall == 1){
                continue;
            }else{
                ans += cost[wall][1];
            }
        }
    }

    cout << ans;
}