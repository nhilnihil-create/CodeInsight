#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, h;
  cin >> n >> h;
  vector<int> an(n), bn(n);
  for(int i=0; i<n; ++i) cin >> an[i] >> bn[i];
  int mxan = 0;
  for(int i=0; i<n; ++i) mxan = max(mxan, an[i]);
  sort(bn.begin(),bn.end());
  reverse(bn.begin(),bn.end());
  int ans = 0;
  for(int i=0; i<n; ++i){
    if(bn[i] < mxan || h <= 0) break;
    h -= bn[i];
    ++ans;
  }
  if(h>0) ans += (h-1)/mxan +1;
  cout << ans << endl;
}