#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<sstream>
#include<bitset>
using namespace std;
#define pii pair<int,int>
#define pdd pair<double,double>
#define mp make_pair
#define pb push_back
#define ALL(x)	x.begin(),x.end()
#define fst first
#define sec second
#define PQ priority_queue
typedef long long ll;
const double eps = 1e-6;
const int maxn=1e6+10;;
const int inf=0x3f3f3f3f;
const ll mod=1e9+7;
const double pi=acos(-1.0);
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;} 
ll vis[maxn];
int main() {
    ll n,t=0,x=0,tem=0;
    cin>>n;    
    ll lim=sqrt(n);
    ll ans=0;
    for(ll i=1;i<=lim;++i)
    {
      if(n%i==0&&vis[i]==0)
      {
        t=i;
        x=n/i;
        vis[t]=1;
        if(t>1&&n%(t-1)!=0)
        {
           if(n/(t-1)==n%(t-1)) ans+=(t-1);
           //vis[t]=1;
           
        }
        if(x>1&&n%(x-1))
        {
            if(n/(x-1)==n%(x-1)) ans+=(x-1);
            //vis[x]=1;
        }
        else continue;
      }
      else continue;
      
    }
    cout<<ans<<endl;
    return 0;
}