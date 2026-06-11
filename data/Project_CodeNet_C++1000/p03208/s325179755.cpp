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
  cin >> n>> k;
  ll h[n];
  for(ll i=0;i<n;i++)cin >> h[i];

  sort(h,h+n);
  ll ans=inf;
  for(ll i=0;i<n-k+1;i++){
    ans=min(ans,h[i+k-1]-h[i]);
  }
  //for(ll i=0;i<n;i++)cout << h[i] << endl;
  cout << ans << endl;

}