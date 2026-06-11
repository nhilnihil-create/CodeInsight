#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,i,j,k,n74=0,n24=0,n14=0,n4=0,n2=0,ans=0;
  cin>>n;
  vector<int> p;
  p.push_back(2);
  for(i=3;i<100;i++){
    for(j=0;j<p.size();j++) if(i%p.at(j)==0) break;
    if(j==p.size()) p.push_back(i);
  }
  vector<int> c(p.size());
  for(i=2;i<=n;i++){
    k=i;
    for(j=0;j<p.size();j++){
      while(k%p.at(j)==0){
        c.at(j)++;
        k/=p.at(j);
      }
      if(k==1) break;
    }
  }
  for(i=0;i<c.size();i++){
    if(c.at(i)>=2){
      n2++;
      if(c.at(i)>=4){
        n4++;
        if(c.at(i)>=14){
          n14++;
          if(c.at(i)>=24){
            n24++;
            if(c.at(i)>=74) n74++;
          }
        }
      }
    }
  }
  ans+=n74;
  if(n2>=1) ans+=n24*(n2-1);
  if(n4>=1){
    ans+=n14*(n4-1);
    if(n2>=2) ans+=n4*(n4-1)/2*(n2-2);
  }
  cout<<ans<<endl;
}