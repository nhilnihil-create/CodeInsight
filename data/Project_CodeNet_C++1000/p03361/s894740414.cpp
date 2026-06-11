#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int h,w;
    cin>>h>>w;
    vector<vector<char>>grid(h,vector<char>(w));
    rep(i,h)rep(j,w)cin>>grid[i][j];
    const int dx[4]={1, 0, -1, 0};
    const int dy[4]={0, 1, 0, -1};
    bool ans=true;
    rep(i,h)rep(j,w){
        if(grid[i][j]=='#'){
            bool found=false;
            for (int dir = 0; dir < 4; ++dir) {
                int nh = i + dx[dir];
                int nw = j + dy[dir];

                if (nh >= 0 && nh < h && nw >= 0 && nw < w && grid[nh][nw]=='#'){
                    found=true;
                }
            }
            if(!found)ans=false;
        }
    }
    if(ans)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}