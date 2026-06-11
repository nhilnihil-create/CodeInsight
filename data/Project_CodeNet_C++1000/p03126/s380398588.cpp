#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  ll n,m;
  cin >> n >> m;

  ll suki[m]={};
  for(ll i=0;i<n;i++){
    ll k;
    cin >> k;
    for(ll j=0;j<k;j++){
      ll a;
      cin >> a;
      suki[a-1]++;
    }
  }
  ll s=0;
  for(ll i=0;i<m;i++)if(suki[i]==n)s++;

  cout << s << endl;

}