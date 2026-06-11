# include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pii pair<int,int>
typedef long long ll;
int n,m,dis[1005][1005];
char arr[1005][1005];
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

queue<pair<int,pii > >q;
bool inside(int x,int y){
    return x>=1 && x<=n && y>=1 && y<=m;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>m;
    memset(dis,-1,sizeof(dis));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>arr[i][j];
            if(arr[i][j]=='#'){
                dis[i][j]=0;
                q.push({i,{j,0}});

            }
        }
    }
    
    while(q.empty()==false){
        int r=q.front().fi;
        int c=q.front().se.fi;
        int cnt=q.front().se.se;
        q.pop();
        for(int i=0;i<4;i++){
            int nr=r+dx[i];
            int nc=c+dy[i];
            if(dis[nr][nc]==-1 && inside(nr,nc)){
                q.push({nr,{nc,cnt+1}});
                dis[nr][nc]=cnt+1;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            ans=max(ans,dis[i][j]);
        }

    }
    cout<<ans<<endl;

}