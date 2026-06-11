#include<bits/stdc++.h>
using namespace std;
using ull=unsigned long long;
#define mod 1000000007
#define mod2 998244353 
#define PI 3.14159265
#define ll long long
#define ld long double
#define pi pair<ll,ll>
#define pb push_back
#define vi vector<ll>
#define sz size()
#define setbits(x)  __builtin_popcount(x)
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
 
 
 
 
 
 
 




 char s[1005][1005];
 int dist[1005][1005];
 int dx[]={1,-1,0,0};
 int dy[]={0,0,-1,1};
int main()
{
    int h,w;
    cin>>h>>w;
   
    for(int i=1;i<=h;i++){
         string t;
         cin>>t;
         for(int j=0;j<t.length();j++){
              s[i][j+1]=t[j];
         }
    }
    memset(dist,-1,sizeof(dist));
    queue<pair<int,int>> q;
    for(int i=1;i<=h;i++){
         for(int j=1;j<=w;j++){
              if(s[i][j]=='#'){
                   q.push({i,j});
                   dist[i][j]=0;
              }
         }
    }
    int ct=0;
    while(!q.empty()){
         int x=q.front().fi,y=q.front().se;
         q.pop();
         for(int i=0;i<4;i++){
              int nx=x+dx[i],ny=y+dy[i];
              if(nx<1||nx>h||ny<1||ny>w||s[nx][ny]=='#')continue;
              if(dist[nx][ny]==-1){
                   dist[nx][ny]=1+dist[x][y];
                   q.push({nx,ny});
              }
         }

    }
    int mx=0;
    for(int i=1;i<=h;i++){
         for(int j=1;j<=w;j++){
              mx=max(mx,dist[i][j]);
         }
    }
    cout<<mx;

}


































