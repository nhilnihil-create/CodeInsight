#include <bits/stdc++.h>
using namespace std;
 
#define clr(i, j)     memset(i, j, sizeof(i))
#define pb            push_back
 #define PI acos(-1)
 #define MOD ((int)1e9+7)
typedef long long     ll;
 
//-*-*-*-*-*-*-*-*-
 
 

 
const int N=2e5+100;
ll visited[100005];
//ll a[200000];
 

#define lop(i,n) for(int i=0;i<n;++i)
//ll n,m,mod;

int dx[4] = {1 , 0 , 0 , -1} ;
int dy[4] = {0 , 1 , -1 , 0} ;

const int MAX = 2e5 + 10 ;
void finis(){cout<<-1;}
vector<pair<int,int>>v;

int a[3001][100];ll h,w;
int valid(ll x,ll y){
    if(x<=0||x>h||y<=0||y>w||a[x][y]==1){return 0;}
    return 1;
}ll ans[100][100];
int main()
{  ios::sync_with_stdio(0);
cin.tie(0);
cin>>h>>w;ll lol=0;
for(int i=1;i<=h;i++){
   for(int j=1;j<=w;j++){
       char xx;cin>>xx;if(xx=='#'){ lol++;a[i][j]=1;}ans[i][j]=10000007;
       
   }
}queue<pair<ll,ll>>q;ans[1][1]=0;
q.push({1,1});
while(!q.empty()){
    pair<ll,ll>l=q.front();
    q.pop();
    ll x=l.first;ll y=l.second;
    ll myans=ans[x][y];
    for(int j=0;j<4;j++){
        ll xx=x+dx[j];
        ll yy=y+dy[j];
        if(valid(xx,yy)&&myans+1<ans[xx][yy]){
            q.push({xx,yy});ans[xx][yy]=myans+1;
        }
    }
}if(a[1][1]||a[h][w]||ans[h][w]==10000007){cout<<-1;return 0;}
cout<<(h*w)-(ans[h][w]+1)-lol;

   
}
