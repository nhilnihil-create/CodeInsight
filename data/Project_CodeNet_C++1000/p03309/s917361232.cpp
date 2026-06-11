#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define INF 1e18
#define PI 3.14159265358979

using namespace std;

int main(void){
  ll n;
  cin >> n;
  
  vector<ll> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
    a[i] -= i + 1;
  }
  sort(a.begin(), a.end());

  if (n % 2 == 1){
    ll res = 0;
    ll t = (a[n/2] + a[(n-1)/2])/2;
    for (int i = 0; i < n; i++){
      res += abs(t - a[i]);
    }
    cout << res << endl;
  }
  else {
    ll res = 0;
    ll t = a[n/2];
    for (int i = 0; i < n; i++){
      res += abs(t - a[i]);
    }
    cout << res << endl;
  }
  
  

  return 0;
}
