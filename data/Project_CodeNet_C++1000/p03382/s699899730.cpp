#include<bits/stdc++.h>
using namespace std;
 
int main(){
  int n; cin >> n;
  vector<int> a(n); for(int i=0;i<n;i++) cin >> a[i];
  sort(a.begin(),a.end());
  int r = a[n-1];
  int idx = upper_bound(a.begin(),a.end(),r/2) - a.begin();
  int l, dif = INT_MAX;
  for(int i=0;i<n-1;i++){
  	if(abs(2 * a[i] - r) < dif){dif = abs(2*a[i] - r); l = a[i];}
  }
  cout << r << " " << l << endl; 
  return 0;
}
  