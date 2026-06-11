#include<bits/stdc++.h>
#define ll long long int
#define vec vector<ll>
#define mat vector<vec>

using namespace std;

const ll mod=1000000007;
const ll inf=LONG_LONG_MAX;
ll dx4[4]={1,0,-1,0};
ll dy4[4]={0,-1,0,1};
ll dx8[8]={1,0,-1,1,-1,1,0,-1};
ll dy8[8]={1,1,1,0,0,-1,-1,-1};

int main(){

  ll n,k;
  cin >> n >> k;

  ll ans=0;
  for(ll b=k+1;b<=n;b++){
    ll a=n/b;
    ll c=n%b;
    ans+=(b-k)*a;
    if(c>=k)ans+=(c-k+1);
  }

  if(k!=0)cout << ans << endl;
  else cout << n*n << endl;
}