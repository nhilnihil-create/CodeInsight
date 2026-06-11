#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,t,a;
  cin>>n>>t>>a;
  vector<int>h(n);
  for(int i=0;i<n;i++)cin>>h[i];
  vector<double>kion(n);
  for(int i=0;i<n;i++){
    kion[i]=(double)t-h[i]*0.006;
    //cout<<kion[i]<<endl;
  }
  double sa=LLONG_MAX;
  int kotae=0;
  for(int i=0;i<n;i++){
    double tmp=fabs(kion[i]-(double)a);
    //cout<<i<<" "<<tmp<<endl;
    if(sa>tmp){
      kotae=i+1;
      sa=tmp;
    }
  }
  cout<<kotae<<endl;
  return 0;
}

