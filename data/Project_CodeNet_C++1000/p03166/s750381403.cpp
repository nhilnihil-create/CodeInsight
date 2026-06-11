#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

vector<vector<int>> v(100005);
int dp[100005];

int go(int i){
    if(dp[i]!=-1){
        return dp[i];
    }

    int path = 0;
    for(auto x: v[i]){
        path = max(path, 1 + go(x));
    }

    return dp[i]=path;
}

int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
       int x,y;
       cin >> x >> y;
       v[x].push_back(y);
    }

    memset(dp, -1, sizeof(dp));

    int ans = 0;
    for(int i = 0; i <= n; i++){
       ans = max(ans, go(i));
    }
    
    cout << ans << endl;
    

}
