#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

ll gcd(ll a,ll b){
  if(a < b) return gcd(b, a);
    int r;
    while ((r=a%b)) {
    a = b;
    b = r;
  }
  return b;
}

int main(){

  ll a,b,k;
  cin >> a >> b >> k;

  ll d=gcd(a,b);
  vector<ll> v;
  for(int i=1;i<d+1;i++)if(d%i==0)v.push_back(i);

  cout << v[v.size()-k] << endl;

}