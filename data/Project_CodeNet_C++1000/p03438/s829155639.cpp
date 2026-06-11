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













bool compare(pi a,pi b){
     if(a.fi-a.se>b.fi-b.se)return  true;
     else if(a.fi-a.se==b.fi-b.se&&a.se<b.se)return true;
     return false;
}




const int N=1000005;
int pr[1000005];
int main()
{
     int n;
     cin>>n;
     int a[n],b[n];
     ll suma=0,sumb=0;
     for(int i=0;i<n;i++){cin>>a[i];suma+=a[i];}
     for(int i=0;i<n;i++){cin>>b[i];sumb+=b[i];}
     if(suma>sumb){cout<<"No";return 0;}
     ll dif=0;
     for(int i=0;i<n;i++){
          if(a[i]<b[i]){
               dif+=(b[i]-a[i]+1)/2;
          }
     }
     if(dif<=sumb-suma)cout<<"Yes";
     else cout<<"No";

    

}




 
 















