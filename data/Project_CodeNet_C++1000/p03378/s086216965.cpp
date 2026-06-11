#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,m,x;
  cin>>n>>m>>x;
  vector<int>a(m);
  
  for(int i=0;i<m;i++){
    cin>>a[i];
  }
  
  int ansl=0;
  int ansr=0;
  
  for(int i=0;i<m;i++){
    if(a[i]>0 && a[i]<x){
      ansl++;
    }
    if(a[i]>x && a[i]<n){
      ansr++;
    }
  }
  cout<<min(ansl,ansr)<<endl;
  
}
