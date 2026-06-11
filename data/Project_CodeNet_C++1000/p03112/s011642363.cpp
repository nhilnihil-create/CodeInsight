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
 
 
 
 
 
 
 







int last[200005];
int main(){
    int a,b,q;
    cin>>a>>b>>q;
    vector<ll> s(a);
    vector<ll> t(b);
    for(int i=0;i<a;i++)cin>>s[i];
    for(int i=0;i<b;i++)cin>>t[i];
    s.push_back(-1e17);
    t.push_back(-1e17);
    s.push_back(1e17);t.push_back(1e17);
    sort(s.begin(),s.end());sort(t.begin(),t.end());
    while(q--){
         ll x;
         cin>>x;
         int idx1=lower_bound(s.begin(),s.end(),x)-s.begin();
         int idx2=lower_bound(t.begin(),t.end(),x)-t.begin();
         ll a=s[idx1]-x;
         ll b=t[idx2]-x;
         ll la=x-s[idx1-1];
         ll lb=x-t[idx2-1];
         ll ans=1e18;
         ans=min(ans,max(a,b));
         ans=min(ans,max(la,lb));
         ans=min(ans,lb+a+min(a,lb));
         ans=min(ans,b+la+min(la,b));
         cout<<ans<<"\n";
         
    }
}




































