#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n; cin >> n;
  vector<int> a(n);
  int mx = 0;
  for(int i = 0; i < n; i++){
    cin >> a[i];
    mx = max(mx,a[i]);
  }

  int mid = mx / 2,r;
  int res = 1e9;
  for(int i = 0; i < n; i++){
    if(a[i] == mx) continue;
    if(abs(mid - a[i]) < res){
      res = abs(mid - a[i]);
      r = a[i];
    }
  }
  cout << mx << " " << r << endl;

  return 0;
}
