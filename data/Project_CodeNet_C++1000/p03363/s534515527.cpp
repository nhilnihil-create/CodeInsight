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



int main()
{
    ll n;
    cin>>n;
    ll a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    map<ll,int> mp;
    ll sum=0;
    for(int i=0;i<n;i++)
    {
         sum+=a[i];
         mp[sum]++;
    }
    ll res=0;
    for(auto it:mp)
    {
         if(it.first==0){
              res+=1LL*it.second;
              if(it.second>=2)
              res+=1LL*(it.second)*(it.second-1)/2;
         }
         else
         {
              int ct=it.second;
              if(ct>=2){
                   res+=1LL*(ct)*(ct-1)/2;
              }
         }
    }
    cout<<res;
}















 














 
 















