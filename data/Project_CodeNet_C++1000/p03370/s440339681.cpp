#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,x,mn=100000,kl=0;
  cin>>n>>x;
  vector<int>m(n);
  for(int i=0;i<n;i++){
    cin>>m[i];
  }
  for(int i=0;i<n;i++){
    x-=m[i];
    kl++;
  }
  for(int i=0;i<n;i++){
    mn=min(mn,m[i]);
  }
  cout<<kl+x/mn<<endl;
}

    
    
  
  