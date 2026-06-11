#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define mod2 998244353 
#define PI 3.14159265
#define ll long long
#define ld long double
#define pi pair<ll,ll>
#define pb push_back
#define vi vector<ll>
#define sz size()
#define fi first
#define se second
#define lz length()
#define all(x) (x).begin(),(x).end()
#define scf(x) scanf("%lld",&x)
#define rep(i,n) for(ll i=0;i<n;i++)
const int INF = (int)1e9;
const ll IINF=1LL<<62;
const int maxn=10000005;
//int divr[maxn];
/**/
/*void divisor()
{for(int i=2;i<sqrt(maxn);i++)
     {
          if(!divr[i])
          {
               for(int j=i*i;j<maxn;j+=i)if(!divr[j])divr[j]=i;     
          }
     }
     for(int i=1;i<maxn;i++)if(!divr[i])divr[i]=i;
}*/
 
/*const int N=1000005;
ll n;
struct line {
    long long m, c;
    long long eval(long long x) { return m * x + c; }
    long double intersectX(line l) { return (long double) (c - l.c) / (l.m - m); }
};
vector<pair<pi,ll>> rect;
deque<line> dq;
*/
ll modexpo(ll a,ll b)
{
     ll res=1LL;
     while(b>0)
     {
          if(b&1)res=(res*a)%mod;
          a=(a*a)%mod;
          b>>=1;
     }
     return res;
}












int d[55][55];
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
int vis[55][55];
int main()
{
    int h,w;
    cin>>h>>w;
    char s[h+1][w+1];
    int ct=0;
    string t;
    for(int i=1;i<=h;i++){
         cin>>t;
        for(int j=0;j<t.length();j++){
             s[i][j+1]=t[j];
             if(t[j]=='.')ct++;
        }
    }
    if(s[1][1]=='#'||s[h][w]=='#'){cout<<-1;return 0;}
    queue<pair<int,int>> q;
    q.push({1,1});
    memset(vis,0,sizeof(vis));memset(d,-1,sizeof(d));
    vis[1][1]=1;d[1][1]=0;
    while(!q.empty()){
         int x=q.front().fi;
         int y=q.front().se;
         q.pop();
         
         for(int l=0;l<4;l++){
              int nx=x+dx[l],ny=y+dy[l];
              //cout<<x<<" "<<y<<" "<<nx<<" "<<ny<<"\n";
              if(nx<1||nx>h||ny<1||ny>w||s[nx][ny]=='#')continue;
              if(vis[nx][ny]==0){
               d[nx][ny]=1+d[x][y];
               vis[nx][ny]=1;
               q.push(make_pair(nx,ny));
              }
          }
    }
    //cout<<d[h][w]<<"\n";
   if(d[h][w]==-1)cout<<-1;
   else cout<<(ct-d[h][w]-1);


}
 
 
 
 

 
 
 
 
 
 
 
 
 
 
 
 
 

