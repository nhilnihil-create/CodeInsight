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
 
 
 
 
 
 
 




vector<pair<int,int>> adj[100005];
ll dist[100005];
int n;
void dfs(int node,int par){
     for(auto ch:adj[node]){
          if(ch.fi==par)continue;
          dist[ch.fi]=dist[node]+ch.se;
          dfs(ch.fi,node);
     }
}




int main()
{
     int n,m;
     cin>>n>>m;
     vector<pair<int,int>> vec;
     for(int i=0;i<m;i++){
          int x,y;
          cin>>x>>y;
          vec.push_back({x,y});
     }
     sort(vec.begin(),vec.end());
     int ct=0;
     int s=vec[0].fi,e=vec[0].se;
     for(int i=1;i<vec.size();i++){
          int a=vec[i].fi,b=vec[i].se;
          if(a==s){
               e=min(e,b);
          }
          else if(a>s&&a<e){
               s=max(a,s);
               e=min(b,e);
          }
          else if(a>=e){
               ct++;
               s=a;
               e=b;
          }
     }
     if(s<e)ct++;
     cout<<ct;
}




















