#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  ll a,b;
  cin >> a >> b;

  if(a>=b+2)cout << a+a-1 << endl;
  else if(a+2<=b)cout << b+b-1 << endl;
  else cout << max(a,b)+min(a,b) << endl;

}