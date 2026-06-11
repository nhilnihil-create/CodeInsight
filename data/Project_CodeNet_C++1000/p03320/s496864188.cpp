#include<bits/stdc++.h>
using namespace std;
#define inf 1e9
#define ll long long
#define ull unsigned long long
#define M 1000000007
#define P pair<int,int>
#define PLL pair<ll,ll>
#define FOR(i,m,n) for(int i=m;i<n;i++)
#define RFOR(i,m,n) for(int i=m;i>=n;i--)
#define rep(i,n) FOR(i,0,n)
#define rrep(i,n) RFOR(i,n,0)
#define all(a) a.begin(),a.end()
const int vx[4] = {0,1,0,-1};
const int vy[4] = {1,0,-1,0};
#define PI 3.14159265


ll f(ll n){
  if(n==0) return 0;

  return n%10+f(n/10);
}

int main(){
  ll k;
  cin>>k;

  ll n=1;
  ll p=1;
  ll i=0;
  while(i<k){
    cout<<n<<endl;
    ll a=n+p;
    ll b=n+p*10;
    if(a*f(b)<=b*f(a))
      n = a;
    else{
      n = b;
      p*=10;
    }
    i++;
  }


  return 0;
}