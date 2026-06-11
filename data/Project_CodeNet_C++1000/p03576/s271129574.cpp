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
/*int find(int a){
     if(a==par[a])return a;
     return par[a]=find(par[a]);
}
void unite(int a,int b){
     a=find(a),b=find(b);
     if(a==b)return ;
     par[b]=a;
}
ll modexpo(ll a,ll b)
{
     int ans=1LL;
     while(b>0)
     {
          if(b&1)ans=(ans*a)%mod;
          a=(a*a)%mod;
          b>>=1;
     }
     return ans;
}
*/











int n,k;
int x[60],y[60];
vector<pair<int,int>> vec;
int main(){
     cin>>n>>k;
     for(int i=0;i<n;i++){
          cin>>x[i]>>y[i];
     }
     for(int i=0;i<n;i++){
          for(int j=0;j<n;j++){
               vec.pb({x[i],y[j]});
          }
     }
     ll res=-1;
     for(int i=0;i<vec.size();i++){
          for(int j=i+1;j<vec.size();j++){
               int x1=min(vec[i].fi,vec[j].fi);
               int x2=max(vec[i].fi,vec[j].fi);
               int y1=min(vec[i].se,vec[j].se);
               int y2=max(vec[i].se,vec[j].se);
               int ct=0;
               for(int k=0;k<n;k++){
                    if(x1<=x[k]&&x[k]<=x2&&y1<=y[k]&&y[k]<=y2){
                         ct++;
                    }
               }
               if(ct>=k){
                    ll ar=1LL*abs(x2-x1)*abs(y2-y1);
                    if(res==-1)res=ar;
                    else res=min(res,ar);
               }
          }
     }
     cout<<res;
}

















































