#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,a,b;cin>>n>>a>>b;
  vector<int>p(n);
  for(int i=0;i<n;i++)cin>>p.at(i);
  sort(p.begin(),p.end());
  int k,l;
  for(int i=0;i<n;i++){
    if(p.at(i)>a){
      k=i;
      break;
    }
  }
  for(int i=n-1;i>=0;i--){
    if(p.at(i)<=b){
      l=n-i-1;
      break;
    }
  }
  int m=min(k,l);
  m=min(m,n-k-l);
  cout<<m<<endl;
}
