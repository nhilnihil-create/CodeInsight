#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll n, ll m){
  if(n%m==0) return m;
  else {
      return gcd(m, n%m);;
  }
}

int main(){
    int n; ll X; cin>>n>>X;
    ll x; cin >> x;
    ll ans = abs(x-X);
    ll num = 0;
    for (int i=0; i<n-1; i++){
        if(ans == 1) break;
        cin >> x;
        ll tmp = abs(x-X);
        ans = gcd(ans, tmp);
    }
    cout << ans << endl;
}