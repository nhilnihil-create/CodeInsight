#include <bits/stdc++.h>
using namespace std;

main(){
  vector<int> a(3);for(int i=0;i<3;i++) cin >> a[i];
  sort(a.begin(),a.end());
  int sum=0;for(int i=0;i<3;i++) sum+=a[i];
  int ans=0;
  int x=a[2];
  int diff=3*x - sum;
  if(diff%2 == 0){
    ans = diff/2;
  } else {
    x++;
    diff=3*x-sum;
    ans = diff/2;
  }
  cout << ans << endl;
  return 0;
} 