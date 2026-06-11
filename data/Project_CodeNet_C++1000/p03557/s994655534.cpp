#include<bits/stdc++.h>
#define rep(i,f,n) for(int i=(f); (i) < (n); i++)
#define repe(i,f,n) for(int i=(f); (i) <= (n); i++)
using namespace std;

typedef long long ll;

int main() {
  int n; cin >> n;
  vector<int> arr(n);
  vector<int> brr(n);
  vector<int> crr(n);
  rep(i, 0, n) cin >> arr[i]; 
  rep(i, 0, n) cin >> brr[i]; 
  rep(i, 0, n) cin >> crr[i];
  
  sort(arr.begin(), arr.end());
  sort(crr.begin(), crr.end());

  ll ans = 0;
  rep(i, 0, n){
    auto lower_a = lower_bound(arr.begin(),arr.end(),brr[i]);
    auto higher_c = upper_bound(crr.begin(),crr.end(),brr[i]);
    ans += (lower_a - arr.begin()) * (crr.end() - higher_c);
  }
  
  cout << ans << endl;

  return 0;
}