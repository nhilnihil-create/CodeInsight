#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  int n; cin >> n;
  int a[n];
  for(int i = 0; i < n; ++i) cin >> a[i];
  int b[n];
  for(int i = 0; i < n; ++i) b[i] = a[i] - (i + 1);
  sort(b,b + n);
  int mid = b[n/2];
  ll ans = 0;
  for(int i = 0; i < n; ++i){
    ans += (ll)abs(b[i] - mid);
  }
  cout << ans << '\n';
}