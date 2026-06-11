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

  ll n;
  cin >> n;
  ll p[n];
  for(ll i=0;i<n;i++)cin >> p[i];
  sort(p,p+n);
  ll ans=0;
  for(ll i=0;i<n-1;i++)ans+=p[i];
  ans+=p[n-1]/2;

  cout << ans << endl;

}