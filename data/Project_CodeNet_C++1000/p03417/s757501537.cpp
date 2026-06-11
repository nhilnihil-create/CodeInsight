#include <bits/stdc++.h>
#include <math.h>
using namespace std;
using ll = long long;

int main(){
  ll n, m;
  cin >> n >> m;
  if(n == 1 || m == 1){
    if(n == 1 && m != 1){cout << max(m-2, 0LL) << endl;}
    else if(m == 1 && n != 1){cout << max(n-2, 0LL) << endl;}
    else{cout << 1 << endl;}
    }
  else{
    ll ans = (n-2) * (m-2);
    cout << ans << endl;
  }
}
