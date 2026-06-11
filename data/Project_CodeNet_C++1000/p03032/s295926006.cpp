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
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    ll res=0;
    for(int i=-1;i<=n;i++){
         for(int j=i+1;j<=n;j++){
              if(i+1+n-j>k)continue;
              int z=k-(i+1+n-j);
              ll sum=0;
              vector<int> tmp;
              for(int k=0;k<=i;k++){sum+=a[k];
              if(a[k]<0)
              tmp.push_back(a[k]);}
              for(int k=j;k<n;k++){sum+=a[k];
              if(a[k]<0)tmp.push_back(a[k]);}
              sort(tmp.rbegin(),tmp.rend());
              while(!tmp.empty()&&z>0){
                   sum+=abs(tmp.back());tmp.pop_back();
                   z--;
              }
              //cout<<sum<<"\n";
              res=max(res,sum);
         }
    }
    cout<<res;

}

































