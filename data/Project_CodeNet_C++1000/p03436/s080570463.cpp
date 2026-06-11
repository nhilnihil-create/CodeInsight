#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;

int main(){
    ll h,w;cin >>h>>w;
    vector<vector<ll>>cost(w,vector<ll>(h,INF));
    char s[w][h];
    ll white=0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >>s[j][i];
            if(s[j][i]=='.')white++;
        }
    }
    ll dx[4]={0,1,-1,0};
    ll dy[4]={1,0,0,-1};
    queue<P>que;
    que.push({0,0});
    cost[0][0]=1;
    while(!que.empty()){
        P pos=que.front();
        que.pop();
        ll x=pos.first;
        ll y=pos.second;
        for (int i = 0; i < 4; ++i) {
            ll tx=x+dx[i];
            ll ty=y+dy[i];
            if(tx>=w||ty>=h)continue;
            if(tx<0||ty<0)continue;
            if(s[tx][ty]=='#')continue;
            if(cost[tx][ty]>cost[x][y]+1) {
                cost[tx][ty] = min(cost[tx][ty], cost[x][y] + 1);
                que.push({tx, ty});
            }
        }
    }
    ll ans;
//    for (int i = 0; i < h; ++i) {
//        for (int j = 0; j < w; ++j) {
//            cout <<cost[j][i]<<" ";
//        }
//        cout <<endl;
//    }
    if(cost[w-1][h-1]==INF)ans=-1;
    else {
        ans=white-cost[w-1][h-1];
    }
    cout <<ans<<endl;
    return 0;
}

