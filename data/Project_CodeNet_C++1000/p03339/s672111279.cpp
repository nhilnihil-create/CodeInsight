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
  string s;
  cin >> n >> s;

  vec a(n+1);
  for(ll i=0;i<n;i++){
    a[i+1]=a[i];
    if(s[i]=='W')a[i+1]++;
  }

  ll ans=inf;
  ans=min(ans,n-1-a[n]+a[1]);
  //cout << ans << " " <<  0 << endl;
  for(ll i=1;i<n-1;i++){
    ans=min(ans,a[i]+(n-i-1)-(a[n]-a[i+1]));
    //cout << ans << " " << i << " " << a[i]+(n-i-1)-(a[n]-a[i+1]) << endl;
  }
  ans=min(ans,a[n-1]);
  //cout << ans << " " << n-1 << endl;

  cout << ans << endl;


}