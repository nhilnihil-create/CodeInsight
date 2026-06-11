#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> dn(n);
  for(int i=0; i<n; ++i) cin >> dn[i];
  sort(dn.begin(),dn.end());
  bool p = true;
  vector<int> ans(n+1);
  ans[0] = 0;
  for(int i=1; i<=n; ++i){
    ans[i] = (p ? dn[i-1]: 24 -dn[i-1]);
    p = (p ? false:true);
  }
  sort(ans.begin(),ans.end());
  int num = 24;
  for(int i=0; i<=n; ++i){
    if(i == n) num = min(num,24 - ans[n]);
    else{
      num = min(num, ans[i+1] - ans[i]);
    }
  }
  cout << num << endl;
}