#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >>n;
  vector<int>a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  long long kotae=a[0];
  for(int i=1;i<n;i++){
    if(a[i]-a[i-1]>0)kotae+=a[i]-a[i-1];
  }
  cout<<kotae<<endl;
  return 0;
}
