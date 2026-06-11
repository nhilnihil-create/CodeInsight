#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  ll n,a,b,c,d,e;
  cin >> n>> a >> b >> c >>d >>e;

  ll f=a;
  f=min(f,b);
  f=min(f,c);
  f=min(f,d);
  f=min(f,e);

  ll m;
  if(n%f==0)m=n/f;
  else m=n/f+1;
  cout << 4 + m << endl;


}
