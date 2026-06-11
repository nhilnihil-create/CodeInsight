#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  ll x,y,z,k;
  cin >> x >> y >> z >> k;
  ll a[x],b[y],c[z];

  for(int i=0;i<x;i++)cin >> a[i];
  for(int i=0;i<y;i++)cin >> b[i];
  for(int i=0;i<z;i++)cin >> c[i];

  sort(c,c+z);
  reverse(c,c+z);

  vector<ll> v;
  for(int i=0;i<x;i++){
    for(int j=0;j<y;j++){
      v.push_back(a[i]+b[j]);
    }
  }

  sort(v.begin(),v.end());
  reverse(v.begin(),v.end());

  vector<ll> u;

  for(int i=0;i<min(k,x*y);i++){
    for(int j=0;j<z;j++){
      u.push_back(v[i]+c[j]);
    }
  }

  sort(u.begin(),u.end());
  reverse(u.begin(),u.end());

  for(int i=0;i<k;i++)cout << u[i] << endl;
  
  

  

}