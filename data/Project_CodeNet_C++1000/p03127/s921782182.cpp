#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

ll gcd(ll a,ll b){
  if(a%b == 0){
    return b;
  }else{
    return gcd(b, a%b);
  }
}

ll lcm(ll a,ll b){
  return a/gcd(a,b)*b;
}

int main(){

  ll n;
  cin >> n;
  ll a[n];
  for(ll i=0;i<n;i++)cin >> a[i];

  ll l=a[0];
  for(ll i=1;i<n;i++)l=gcd(l,a[i]);
  cout << l << endl;


}