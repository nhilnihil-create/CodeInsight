#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int m=0;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin>>a.at(i);
    m=(abs(a.at(m))<abs(a.at(i))?i:m);
  }
  cout<<2*(n-1)<<endl;
  for(int i=0;i<n;i++)
    if(i!=m)
      cout<<m+1<<" "<<i+1<<endl;
  if(a.at(m)>0)
    for(int i=1;i<n;i++)
      cout<<i<<" "<<i+1<<endl;
  else
    for(int i=n;i>1;i--)
      cout<<i<<" "<<i-1<<endl;
}