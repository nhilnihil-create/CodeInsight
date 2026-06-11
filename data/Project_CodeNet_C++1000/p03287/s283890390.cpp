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
/*ll modexpo(ll a,ll b)
{
     ll ans=1LL;
     while(b>0)
     {
          if(b&1)ans=(ans*a)%mod;
          a=(a*a)%mod;
          b>>=1;
     }
     return ans;
}
int find(int a){
     if(par[a]==a)return a;
     return par[a]=find(par[a]);
}
void unite(int a,int b){
     a=find(a),b=find(b);if(a==b)return ;
     parent[b]=a;
}*/
 
 
 
 
 
 
 












int main(){
     ll n,m;
     cin>>n>>m;
     vector<ll> a(n);rep(i,n)cin>>a[i];
     ll pre[n+1];
     pre[0]=0;
     map<ll,int> mp;
     int ct0=0;
     for(int i=0;i<n;i++){
          pre[i+1]=(pre[i]+a[i])%m;
          if(pre[i+1]==0)ct0++;
          mp[pre[i+1]]++;
     }
     ll res=0LL;
     for(auto it:mp){
          res+=1LL*it.se*(it.se-1)/2;
     }
     res+=ct0;
     cout<<res;

     
}
























