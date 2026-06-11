#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(a) a.begin(), a.end()
#define mod 1000000007
#define MOD 998244353
#define INF 40000000000000000
int dx8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dy8[8] = {1, 1, 1, 0, -1, -1, -1, 0};
int dx4[4] = {-1, 0, 1, 0};
int dy4[4] = {0, -1, 0, 1};
template <class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}
int solve(int x){
    int r=0,l=1000000000;
    while(l-r>1){
        int mid=(r+l)/2;
        if(mid*mid>x)l=mid;
        else r=mid;
    }
    return r;
}
signed main() {
    int H,W;cin>>H>>W;
    vector<vector<int>>Grid(H,vector<int>(W,-1));
    queue<pair<int,int>>que;
    rep(i,H){
        string s;cin>>s;
        rep(j,W){
            if(s[j]=='#'){
                Grid[i][j]=0;
                que.push(make_pair(i,j));
            }
        }
    }
    int ans=0;
    while(!que.empty()){
        pair<int,int>p=que.front();que.pop();
        int x=p.first,y=p.second;
        chmax(ans,Grid[x][y]);
        rep(i,4){
            int nx=x+dx4[i],ny=y+dy4[i];
            if(nx<0||nx>=H||ny<0||ny>=W)continue;
            if(Grid[nx][ny]==-1){
                Grid[nx][ny]=Grid[x][y]+1;
                que.push(make_pair(nx,ny));
            }
        }
    }
    cout<<ans<<endl;
    
    
}
