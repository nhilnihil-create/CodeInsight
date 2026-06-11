#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  bool ad=false;
  vector<string>w(n);
  for(int i=0;i<n;i++){
    cin>>w[i];
  }
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      if(w[i]==w[j]){
        ad=true;
        break;
      }
    }
    if(ad) break;
  }
  for(int i=0;i<n-1;i++){
    if(w[i].back()!=w[i+1].front()){
      ad=true;
      break;
    }
  }
  if(ad) cout<<"No"<<endl;
  else cout<<"Yes"<<endl;
}
  
        
  
