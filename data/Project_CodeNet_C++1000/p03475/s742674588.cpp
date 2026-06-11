#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,t,i,j;
  cin>>n;
  vector<int> c(n-1),s(n-1),f(n-1);
  for(i=0;i<n-1;i++) cin>>c.at(i)>>s.at(i)>>f.at(i);
  for(i=0;i<n;i++){
    if(i==n-1) cout<<0<<endl;
    else{
      t=0;
      for(j=i;j<n-1;j++){
        t=(max(t,s.at(j))+f.at(j)-1)/f.at(j)*f.at(j)+c.at(j);
      }
      cout<<t<<endl;
    }
  }
}