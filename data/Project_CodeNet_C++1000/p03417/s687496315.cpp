#include <bits/stdc++.h>
#define rep(i, n) for(int i= 0; i < (n); i++)
using ll= long long int;
using namespace std;
ll mod= 1e9 + 7;



int main() {
  ll n,m;
  cin >> n>>m;
  ll ans=0;
  if(n==1 && m==1){cout << 1 << endl; return 0;}
  if(n<=2 && m<=2){cout << 0 << endl; return 0;}
  if(n==1 && m>2){cout << m-2 << endl; return 0;}
  if(m==1 && n>2){cout << n-2 << endl; return 0;}
  if(n>2 && m>2){ans=(n-2)*(m-2);}
  cout << ans << endl;
}