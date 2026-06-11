#include<bits/stdc++.h>
//#include <atcoder/all>
#define ll long long int
#define vec vector<ll>
#define mat vector<vector<ll>>

using namespace std;
//using namespace atcoder;

const ll mod=1000000007;
const ll inf=LONG_LONG_MAX;
ll dx4[4]={1,0,-1,0};
ll dy4[4]={0,-1,0,1};
ll dx8[8]={1,0,-1,1,-1,1,0,-1};
ll dy8[8]={1,1,1,0,0,-1,-1,-1};

int main(){

  ll n;
  cin >> n;
  vec  a(n),b;
  for(ll i=0;i<n;i++)cin >> a[i];

  b=a;
  sort(b.begin(),b.end());
  b.erase(unique(b.begin(),b.end()),b.end());
  sort(a.begin(),a.end());

  ll ans=0;
  for(ll i=0;i<b.size();i++){
    ll p=b[i];
    ll c=upper_bound(a.begin(),a.end(),p)-lower_bound(a.begin(),a.end(),p);
    if(p>c)ans+=c;
    else{
      ans+=(c-p);
    }
  }

  cout << ans << endl;



  return 0;
}