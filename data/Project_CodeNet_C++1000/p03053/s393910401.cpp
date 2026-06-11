
#include <bits/stdc++.h>

#define PI 3.141592653
#define rep(i,a,n) for(int i=a;i<(int)n;++i)
#define SZ(x) ((int)(x).size())	//size() unsigned -> int
#define descSort(a) sort(a.begin(),a.end(),std::greater<int>())
using namespace std;
typedef long long ll;
const ll INF = 1e9 + 7;
ll gcd(ll x,ll y){
    if(x%y==0)return y;
    return gcd(y,x%y);
}

int main(void){
    int h,w;
    cin>>h>>w;
    vector<vector<char>> g(h,vector<char>(w));
    vector<vector<int>> cnt(h,vector<int>(w));
    queue<pair<int,int>> q;
    vector<vector<bool>> visited(h,vector<bool>(w));
    rep(i,0,h){
        rep(j,0,w){
            cin>>g[i][j];
            if(g[i][j]=='#'){
                q.push(make_pair(i,j));
                visited[i][j]=true;
            }
        }
    }
    int dx[4]={0,1,0,-1};
    int dy[4]={-1,0,1,0};
    while(!q.empty()){
        pair<int,int> pos=q.front();q.pop();
        for(int i=0;i<4;i++){
            int nx=pos.first+dx[i];
            int ny=pos.second+dy[i];
            if(nx<0||ny<0||nx>=h||ny>=w || visited[nx][ny])continue;
            visited[nx][ny]=true;
            q.push(make_pair(nx,ny));
            cnt[nx][ny]=cnt[pos.first][pos.second]+1;
        }
    }
    int ans=0;
    rep(i,0,h){
        rep(j,0,w){
            ans=max(ans,cnt[i][j]);
        }
    }
    cout<<ans<<endl;
    return 0;
}