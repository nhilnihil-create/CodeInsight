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
const int vx[4] = {0,1,0,-1};
const int vy[4] = {1,0,-1,0};
#define PI 3.14159265

int n;
ll a[1000000];
ll b[1000000];
ll c[1000000];
ll d[1000000];

bool f(int k){
  ll m = 1<<(k+1);
  rep(i,n){
    c[i]=a[i]%m;
    d[i]=b[i]%m;
  }
  sort(d,d+n);
  ll ans = 0;
  m/=2;
  rep(i,n){
    ans += lower_bound(d,d+n,2*m-c[i])-lower_bound(d,d+n,m-c[i]);
    ans += lower_bound(d,d+n,4*m-c[i])-lower_bound(d,d+n,3*m-c[i]);
  }

  return ans%2;
}


int main(){
  cin>>n;

  rep(i,n){
    cin>>a[i];
  }
  rep(i,n){
    cin>>b[i];
  }

  ll ans=0;

  rep(i,29){
    if(f(i))
      ans += 1 << i;

  }

  cout<<ans<<endl;

  return 0;
}