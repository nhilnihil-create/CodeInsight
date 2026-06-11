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
  vec c(n-1),s(n-1),f(n-1);
  for(ll i=0;i<n-1;i++)cin >> c[i] >> s[i] >> f[i];

  vec ans;

  for(ll i=0;i<n-1;i++){
    ll t=0;
    for(ll j=i;j<n-1;j++){
      t=max(t,s[j]);
      while(t%f[j]!=0)t++;
      t+=c[j];
    }
    ans.push_back(t);
  }


  ans.push_back(0);
  for(ll i=0;i<n;i++)cout << ans[i] << endl;

}