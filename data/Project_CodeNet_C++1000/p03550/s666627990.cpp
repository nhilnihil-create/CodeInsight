#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,z,w;
  cin>>n>>z>>w;
  vector<int> a(n);
  for(int i=0;i<n;i++)
    cin>>a.at(i);
  vector<int> x(n);
  vector<int> y(n);
  for(int i=n-1;i>=0;i--){
    x[i]=abs((i>0?a.at(i-1):w)-a.at(n-1));
    y[i]=abs((i>0?a.at(i-1):z)-a.at(n-1));
    for(int j=i+1;j<n;j++){
      x[i]=max(x[i],y[j]);
      y[i]=min(y[i],x[j]);
    }
  }
  cout<<x[0]<<endl;
}