#include <bits/stdc++.h>
#define ll long long 
using namespace std;
const int mxval = 1e9 + 1;
int main(){

  int n; cin >> n;
  int arr[n + 1];
  int count = 0;
  ll ans = 0;
  int minval = mxval;
  for(int i = 0; i < n; ++i){
    cin >> arr[i];
    if(arr[i] < 0) count++;
    ans += (ll)abs(arr[i]);
    minval = min(minval,abs(arr[i]));
  }
  //cout << count << '\n';
  if(!(count%2)) cout << ans << '\n';
  else cout << (ans - (ll)minval - (ll)minval) << '\n';
}
