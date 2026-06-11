#include <bits/stdc++.h>

using namespace std;

using ll = long long;
constexpr ll MOD = 1e9 + 7;
constexpr ll INF = 1e18;

int main() {
    ll n, m, i, j, k,h,w;
    cin >> h >> w;
    string s[h];
    for(auto &x:s){
        cin >> x;
    }
    ll cnt = 0;
    for(i=0;i<h;i++){
        for(j=0;j<w;j++){
            if(s[i][j]=='.')cnt++;
        }
    }
    vector<vector<int>> cost(h,vector<int>(w,MOD));
    cost[0][0]=1;
    queue<pair<ll,ll>>que;
    que.push({0,0});
    ll dx[]={-1,1,0,0};
    ll dy[]={0,0,-1,1};
    while(!que.empty()){
        auto now = que.front();
        que.pop();
        for(i=0;i<4;i++){
            ll ddx = now.second+dx[i];
            ll ddy = now.first+dy[i];
            if(ddx<0 || ddx>=w)continue;
            if(ddy<0 || ddy>=h)continue;
            if(s[ddy][ddx]=='#')continue;
            if(cost[ddy][ddx]>cost[now.first][now.second]+1){
                que.push({ddy,ddx});
                cost[ddy][ddx]=cost[now.first][now.second]+1;
            }
        }
    }
    if(cost[h-1][w-1]==MOD)cout << -1 << endl;
    else cout << cnt-cost[h-1][w-1] << endl;
    return 0;
}