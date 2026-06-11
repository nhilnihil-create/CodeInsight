#include<bits/stdc++.h>
using namespace std;
int main(void){
  int n; cin>>n;
  vector<int> a(n);
  for(int i=0; i<n; ++i) cin>>a[i];
  sort(a.begin(),a.end());
  double mid=a[n-1]*0.5;
  auto k=upper_bound(a.begin(),a.end(),mid);
  printf("%d ",a[n-1]);
  if(abs(mid-*k)<abs(mid-*(k-1))) cout<<*k; else cout<<*(k-1);
  return 0;
}