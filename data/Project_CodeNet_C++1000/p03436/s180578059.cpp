//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

typedef long long ll;
typedef vector<int> vint;
typedef vector<vector<int> > vvint;
typedef vector<long long> vll, vLL;
typedef vector<vector<long long> > vvll, vvLL;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<n;++i)
#define mod (ll)(1e9+7)
#define FIX(a) ((a)%mod+mod)%mod
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define fi first
#define se second
#define pb push_back
int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int h,w;
    cin >> h >> w;
    int cnt = 0;
    vvint dis(h,vint(w,INF));
    REP(i,h){
        string s;
        cin >> s;
        REP(j,w){
            if(s[j]=='#'){
                dis[i][j]=-1;
                cnt++;
            }else{
                dis[i][j]=INF;
            }
        }
    }
    queue<pair<int,int> > q;
    dis[0][0] = 0;
    q.push(make_pair(0,0));
    while(!q.empty()){
        auto now = q.front();
        q.pop();
        REP(i,4){
            int nx = now.fi+dx[i];
            int ny = now.se+dy[i];
            if(nx<0||nx>=h||ny<0||ny>=w) continue;
            if(dis[nx][ny]==-1) continue;
            if(dis[nx][ny]>dis[now.fi][now.se]+1){
                dis[nx][ny]=dis[now.fi][now.se]+1;
                q.push(make_pair(nx,ny));
            }
        }
    }
    if(dis[h-1][w-1]==INF){
        cout << -1 << endl;
    }else{
        int ans = h*w - dis[h-1][w-1] - cnt - 1;
        cout << ans << endl;
    }

    return 0;
}