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

  ll n,m,x;
  cin >> n >> m >> x;

  ll a[n+1]={};
  for(ll i=0;i<m;i++){
    ll b;
    cin >> b;
    a[b]=1;
  }
  ll p=0,q=0;
  for(ll i=x;i<n;i++)if(a[i])p++;
  for(ll i=x;i>=0;i--)if(a[i])q++;
  cout << min(p,q) << endl;

}