#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < int(n);i++)

int cost[501][501];
int maze[501][501];

int main(){
    int n,c;
    cin >> n >> c;
    rep(i,c) rep(j,c) cin >> cost[i][j];
    rep(i,n) rep(j,n) cin >> maze[i][j];

    vector<vector<int>> ccost(3,vector<int> (c,0));

    rep(i,n) rep(j,n){
        if (((i+1)+(j+1))%3 == 0){
            for (int h = 0; h < c;h++){
                ccost[0][h] += cost[maze[i][j]-1][h];
            }
        }
        else if (((i+1)+(j+1))%3 == 1){
            for (int h = 0; h < c;h++){
                ccost[1][h] += cost[maze[i][j]-1][h];
            }
        }
        else if (((i+1)+(j+1))%3 == 2){
            for (int h = 0; h < c;h++){
                ccost[2][h] += cost[maze[i][j]-1][h];
            }
        }
    }
    //rep(i,c) cout << ccost[0][i];
    //cout << endl;
    //rep(i,c) cout << ccost[1][i];
    //cout << endl;
    //rep(i,c) cout << ccost[2][i];
    //cout << endl;
    int res = 1e9;
    for (int i = 0;i < c;i++){
        for (int j = 0; j < c; j++){
            for (int k = 0; k < c; k++){
                if (i == j || j == k || k == i) continue;
                res = min(res,ccost[0][i]+ccost[1][j]+ccost[2][k]);
            }
        }
    }
    cout << res << endl;

    return 0;

}
