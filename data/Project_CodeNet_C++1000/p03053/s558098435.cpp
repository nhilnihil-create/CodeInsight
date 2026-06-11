#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for (ll i = (a); i < (b); i++)
#define REP(i,n) rep(i,0,n)
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

void solve() 
{
    int h,w;cin>>h>>w;
    int m[h][w];
    queue<pair<int,int> >q;
    REP(i,h)REP(j,w){
        char x;cin>>x;
        if(x=='#')q.push({i,j});
        m[i][j]=(x=='#'?1:0);
    }
    int ans=0;
    while(!q.empty()){
        int y=q.front().first,x=q.front().second;q.pop();
        ans=max(ans,m[y][x]);
        REP(i,4){
            int x2=x+dx[i],y2=y+dy[i];
            if(y2<0||y2>=h||x2<0||x2>=w)continue;
            if(m[y2][x2]==0)m[y2][x2]=m[y][x]+1,q.push({y2,x2});
        }
    }
    cout<<ans-1<<endl;
}

int main()
{
    cin.tie(0);
	ios::sync_with_stdio(false);
    solve();
    return 0;
}