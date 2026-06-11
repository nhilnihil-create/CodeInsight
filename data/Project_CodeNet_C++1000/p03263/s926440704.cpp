#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
typedef long long ll;
using namespace std;
int main(void){
    int h,w;cin>>h>>w;
    int t[h][w];
    rep(i,h)rep(j,w){
        int x;cin>>x;
        t[i][j]=(x%2)? 1:0;
    }
    int res=0;
    queue<pair<int,int>> from,to;
    rep(i,h)rep(j,w-1){
        if(t[i][j]%2==1){
            t[i][j+1]++;
            from.push({i,j});
            to.push({i,j+1});
            res++;
        }
    }
    rep(i,h-1){
        if(t[i][w-1]%2==1){
            t[i+1][w-1]++;
            from.push({i,w-1});
            to.push({i+1,w-1});
            res++;
        }
    }
    cout<<res<<endl;
    rep(i,res){
        auto F=from.front(),T=to.front();
        from.pop();to.pop();
        cout<<F.first+1<<" "<<F.second+1<<" "<<T.first+1<<" "<<T.second+1<<endl;
    }
}
