#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int> c(n+1,0);
  for(int i=1;i<=n;i++){
    c.at(i)=i;
    for(int p=1;p<=i;p*=6)
      c[i]=min(c[i],c[i-p]+1);
    for(int p=1;p<=i;p*=9)
      c[i]=min(c[i],c[i-p]+1);
  }
  cout<<c[n]<<endl;
}