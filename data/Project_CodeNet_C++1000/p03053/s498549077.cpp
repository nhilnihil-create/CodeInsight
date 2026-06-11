///Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>

#define                           int                         long long
#define                           fi                          first
#define                           si                          second
#define                           mp                          make_pair
#define                           pb                          push_back
#define                           pi                          pair<int,int>
#define                           f(i,l,r)                    for(int i=l;i<=r;i++)
#define                           rf(i,r,l)                   for(int i=r;i>=l;i--)
#define                           done(i)                     cout<<"done = "<<i<<endl;
#define                           fast                        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);




using namespace std;

const int inf=1e18;
const int mod=1e9+7;
const int M=100009;

inline int bigmod(int B,int P){int R=1;while(P>0){if(P&1){R=(R*B)%mod;}P>>=1;B=(B*B)%mod;}return R;}
inline int ad(int x,int y){int ret=(x%mod+y%mod)%mod;if(ret<0){ret+=mod,ret=ret%mod;}return ret;}
inline int sub(int x,int y){int ret=((x%mod)-(y%mod)+mod)%mod;if(ret<0){ret+=mod,ret=ret%mod;}return ret;}
inline int gun(int x,int y){int ret=((x%mod)*(y%mod))%mod;if(ret<0){ret+=mod,ret=ret%mod;}return ret;}

int r,c;
string s[1003];
bool vis[1003][1003];
int dis[1003][1003];
inline bool chk(int x,int y)
{
    if(x>=0 && x<r && y>=0 && y<c)return true;
    else return false;
}
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

 main()

{
    fast
    cin>>r>>c;
    queue<pi>q;
    int ses=1;
    f(i,0,r-1)
    {
        cin>>s[i];
        f(j,0,c-1)
        {
            if(s[i][j]=='#')
            {
                q.push(mp(i,j));
                vis[i][j]=1;
                dis[i][j]=1;
            }
        }
    }
    while(!q.empty())
    {
        int x=q.front().fi;
        int y=q.front().si;
        q.pop();
        f(k,0,3)
        {
            int nx=x+dx[k];
            int ny=y+dy[k];
            if(!chk(nx,ny))continue;
            if(vis[nx][ny])continue;
            vis[nx][ny]=1;
            q.push(mp(nx,ny));
            dis[nx][ny]=dis[x][y]+1;
            ses=max(ses,dis[nx][ny]);
        }
    }
    cout<<ses-1<<endl;
    return 0;

}



































