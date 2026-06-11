#include <iostream>
#include <utility>
using namespace std;
#define ll long long

int main () {
  ll n;
  cin >> n;
  ll pm = -1;
  ll pi, mi;
  ll mm = -1;
  ll a[n];
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] >= 0 && pm < a[i]) {
      pm = a[i];
      pi = i;    
    } 
    if (a[i] <= 0 && mm < a[i] * -1) {
      mm = a[i] * -1;  
      mi = i;
    }
  }
  // all +判定
  for (ll i = 0; i < n; i++) {
    if (a[i] < 0) {
      break;  
    }  
    if (i == n - 1) {
      cout << n - 1 << endl;
      for (ll i = 2; i <= n; i++) {
        cout << (i - 1) << " " << i << endl;   
      }  
      return 0;
    }
  }
  for (ll i = 0; i < n; i++) {
    if (a[i] > 0) {
      break;  
    }  
    if (i == n - 1) {
      cout << n - 1 << endl;  
      for (ll i = n - 1; i >= 1; i--) {
        cout << (i + 1) << " " << i << endl;  
      }
      return 0;
    }
  }
  pi++;
  mi++;
  if (pm >= mm) {
    cout << (n - 1) * 2 << endl;
    for (ll i = 1; i <= n; i++) {
      if (i != pi) {
        cout << pi << " " << i << endl;    
      }  
    }  
    for (ll i = 2; i <= n; i++) {
      cout << (i - 1) << " " << i << endl;  
    }
  }
  else {
    cout << (n - 1) * 2 << endl;
    for (ll i = 1; i <= n; i++) {
      if (i != mi) {
        cout << mi << " " << i << endl;  
      }
    }  
    for (ll i = n - 1; i >= 1; i--) {
      cout << (i + 1) << " " << i << endl;  
    }
  }

}