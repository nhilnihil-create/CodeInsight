#include<bits/stdc++.h>
using namespace std;
int main(){
  int X,ans=1;
  cin>>X;
  for(int i=2;i<X;i++)
    for(int j=i*i;j<=X;j*=i)
      ans=max(ans,j);
  cout<<ans<<endl;
}