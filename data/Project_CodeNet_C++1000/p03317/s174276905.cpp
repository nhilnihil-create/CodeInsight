#include <bits/stdc++.h>
#include <math.h>
#include <cmath>
using namespace std;
using ll = long long;


int main(){
  ll n; cin >> n;
  ll k; cin >> k;
  ll m;
  for(int i = 0; i < n; i++){
    int a; cin >> a;
    if(a == 1) m = i;
  }

  ll ans1 = (m + k - 2) / (k - 1) + (n - m + k - 3) / (k - 1);
  for(int i = 1; i < k-1; i++){
    ll ans2 = 1 + (m + k - 2 - i) / (k - 1) + (n - m + k - 3 - k + 1 + i) / (k - 1);
    if(ans2 < ans1){ans1 = ans2;}
  }
  

  cout << ans1 << endl;
}
