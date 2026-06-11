#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,k;
  cin>>n>>k;
  vector<int> x(n);
  for(int i=0;i<n;i++)
    cin>>x.at(i);
  int m=2*(abs(x.at(n-1))+abs(x.at(0)));
  if(0<x.at(0))
    m=x.at(k-1);
  else if(x.at(n-1)<0)
    m=-x.at(n-k);
  else
    for(int i=0;i+k-1<n;i++)
      m=min({m,2*abs(x.at(i))+abs(x.at(i+k-1)),abs(x.at(i))+2*abs(x.at(i+k-1))});
  cout<<m<<endl;
}