#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  ll n,m,c;
  cin >> n>>m >> c;
  ll b[m];
  for(int i=0;i<m;i++)cin >> b[i];

  ll s=0;
  for(int i=0;i<n;i++){
    ll t=0;
    for(int i=0;i<m;i++){
      ll a;
      cin >> a;
      t+=a*b[i];
    }
    if(t+c>0)s++;
  }

  cout << s << endl;

}