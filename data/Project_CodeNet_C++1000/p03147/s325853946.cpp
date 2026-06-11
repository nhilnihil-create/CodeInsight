#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int>h(n);
  int ans=0,active=0;
  for(int i=0;i<n;i++){
    cin>>h[i];
  }
  for(int i=0;i<n;i++){
    if(active>=h[i]){
      active=h[i];
    }
    else{
      ans+=h[i]-active;
      active=h[i];
    }
  }
  cout<<ans<<endl;
}

  
