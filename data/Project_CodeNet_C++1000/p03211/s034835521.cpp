#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  int n,i,ans=1000,k;
  cin>>s;
  n=s.length();
  for(i=0;i<=n-3;i++){
    k=100*(s.at(i)-'0')+10*(s.at(i+1)-'0')+(s.at(i+2)-'0');
    if(abs(k-753)<ans) ans=abs(k-753);
  }
  cout<<ans<<endl;
}