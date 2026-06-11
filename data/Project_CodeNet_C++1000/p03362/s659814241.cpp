#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,i,j,k=0;
  vector<int> p={2};
  cin>>n;
  for(i=3;i<=55555;i+=2){
    for(j=0;j<p.size();j++) if(i%p.at(j)==0) break;
    if(j==p.size()) p.push_back(i);
  }
  for(i=0;i<p.size();i++){
    if(p.at(i)%5==1){
      k++;
      cout<<p.at(i);
      if(k<n) cout<<' ';
      else if(k==n){
        cout<<endl;
        break;
      }
    }
  }
}