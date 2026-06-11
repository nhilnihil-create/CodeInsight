#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;

int di[]={-1,0,1,0};
int dj[]={0,-1,0,1};

int main(){
    int h,w;
    cin>>h>>w;
    vector<string>a(h);
    vector<vector<int>>dist(h,vector<int>(w,1e9));
    vector<pair<int,int>>p;
    rep(i,h)cin>>a[i];
    rep(i,h)rep(j,w)if(a[i][j]=='#')p.push_back(make_pair(i,j));
    queue<pair<int,int>>q;
    auto update=[&](int i, int j, int x){
        if(dist[i][j]!=1e9)return;
        dist[i][j]=x;
        q.push(make_pair(i,j));
    };
    rep(i,p.size()){
        update(p[i].first,p[i].second,0);
    }
    while(!q.empty()){
        int i=q.front().first;
        int j=q.front().second;
        q.pop();
        rep(dir,4){
            int ni=i+di[dir];
            int nj=j+dj[dir];
            if(ni<0||ni>=h||nj<0||nj>=w)continue;
            update(ni,nj,dist[i][j]+1);
        }
    }
    int ans=0;
    rep(i,h)rep(j,w){
        ans=max(ans,dist[i][j]);
    }
    cout<<ans<<endl;
    return 0;
}