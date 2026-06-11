#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int INF = 1e9;

int grid[505][505];
int ans[250005][4];
int main(){
    int h,w; cin >> h >> w;
    rep(i,h)rep(j,w) cin >> grid[i][j];
    int cnt = 0;
    
    rep(i,h)rep(j,w){
        if(j == w-1 && grid[i][j]%2 == 1){
            if(i == h-1) continue;
            ans[cnt][0] = i+1;
            ans[cnt][1] = w;
            ans[cnt][2] = i+2;
            ans[cnt][3] = w;
            grid[i+1][w-1]++;
            cnt++;
            continue;
        }
        if(grid[i][j]%2 == 1){
            ans[cnt][0] = i+1;
            ans[cnt][1] = j+1;
            ans[cnt][2] = i+1;
            ans[cnt][3] = j+2;
            grid[i][j+1]++;
            cnt++;
        }
    }
    
    cout << cnt << endl;
    rep(i,cnt){
        printf("%d %d %d %d\n",ans[i][0],ans[i][1],ans[i][2],ans[i][3]);
    }

}