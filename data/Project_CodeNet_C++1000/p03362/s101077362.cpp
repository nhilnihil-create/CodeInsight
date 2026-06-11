#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int m=55555;
  vector<bool> p(m+1,1);
  for(int i=2;i<=m;i++){
    if(!p.at(i))
      continue;
    for(int j=2;i*j<=m;j++)
      p.at(i*j)=0;
  }
  for(int i=2;i<=m;i++)
    if(i%5!=1)
      p.at(i)=0;
  for(int i=2,c=0;i<=m&&c<n;i++){
    if(p.at(i)){
      c++;
      cout<<i<<(c<n?" ":"");
    }
  }
  cout<<endl;
}