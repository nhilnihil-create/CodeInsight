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
     ll ans=1LL;
     while(b>0)
     {
          if(b&1)ans=(ans*a)%mod;
          a=(a*a)%mod;
          b>>=1;
     }
     return ans;
}
 
 
 
 
 
 
 







ll res[2005];
ll f(ll l,ll r){
     ll w=0;
     for(int i=l;i<=r;i++){w+=res[i];
     }
     return w;
}
int main()
{
     int n;
     cin>>n;
     ll ct[105]={0};
     for(int i=1;i<=n;i++){
          int t=i;
          for(int j=2;j<=sqrt(t);j++){
               if(t%j==0){
                    while(t%j==0){
                         t/=j;ct[j]++;
                    }
               }
          }
          if(t>1)ct[t]++;
     }
     for(int i=2;i<=100;i++)++res[ct[i]+1];
     ll ans=1LL*f(75,2000);
     ans+=f(25,2000)*f(3,24);
     ans+=f(25,2000)*(f(25,2000)-1);
     ans+=f(15,2000)*(f(5,14));
     ans+=f(15,2000)*(f(15,2000)-1);
     ans+=f(5,2000)*(f(5,2000)-1)/2*(f(3,4));
     ans+=f(5,2000)*(f(5,2000)-1)/2*(f(5,2000)-2);
     cout<<ans;

}




















