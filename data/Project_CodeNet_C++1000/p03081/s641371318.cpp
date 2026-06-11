#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n,q; cin >> n >> q;
  string s; cin >> s;
  vector<char> t(q),d(q);
  for(int i = 0; i < q; i++){
    cin >> t[i] >> d[i];
  }

  function< int(int) > check =
  [&](int mid){
    if(n <= mid) return 0LL;
    for(int i = 0; i < q; i++){
      if(s[mid] == t[i]){
        if(d[i] == 'L') mid--;
        else mid++;
      }
      if(mid < 0) return 1LL;
      if(n <= mid) return 2LL;
    }
    return 0LL;
  };

  int ok = -1;
  int ng = n;
  while(ng - ok > 1){
    int mid = (ok + ng) / 2;
    if(check(mid) == 1) ok = mid;
    else ng = mid;
  }
  int left = ok;

  ok = n;
  ng = -1;
  while(ok - ng > 1){
    int mid = (ok + ng) / 2;
    if(check(mid) == 2) ok = mid;
    else ng = mid;
  }

  //cout << left << " " << ok << endl;
  cout << ok - left - 1 << endl;

  return 0;
}
