#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >>n;
  int wa=0;
  vector<int>a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
    wa+=a[i];
  }
  double heikin=(double)wa/(double)n;
  double sa=INT_MAX;
  int kotae=0;
  for(int i=n-1;i>=0;i--){
    double tmp=fabs((double)a[i]-heikin);
    if(sa>=tmp){
      sa=tmp;
      kotae=i;
    }
  }
  cout<<kotae<<endl;
  return 0;
}