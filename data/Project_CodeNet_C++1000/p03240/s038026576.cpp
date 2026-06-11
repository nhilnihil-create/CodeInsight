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
 
 
 
 
 
 
 







int dp[2005][2005];
int f[2005];
int main()
{
     int n;
     cin>>n;
     ll x[n],y[n],h[n];
     for(int i=0;i<n;i++)cin>>x[i]>>y[i]>>h[i];
     ll cx,cy,H;
     for(cx=0;cx<=100;cx++){
          for(cy=0;cy<=100;cy++){
               int res=-1,mn=INT_MAX;
               int f=1;
               for(int i=0;i<n;i++){
                    int t1=abs(cx-x[i]),t2=abs(cy-y[i]);
                    if(res==-1){
                         if(h[i]==0)
                         mn=min(mn,t1+t2);
                         else res=h[i]+t1+t2; 
                    }
                    else{
                         if(max(res-t1-t2,0)!=h[i]){f=0;break;}
                    }
               }
               if(f&&mn!=INT_MAX&&res>mn){}
               else if(!f){}
               else{
                    cout<<cx<<" "<<cy<<" "<<res;return 0;
               }
          }
     }
}
























