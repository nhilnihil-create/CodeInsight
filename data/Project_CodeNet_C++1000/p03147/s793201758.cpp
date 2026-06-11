#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;cin>>n;
  int ans=0;
  vector<int>h(n);
  for(int i=0;i<n;i++){
    cin>>h.at(i);
  }
  while(1){
    int l,r,mini;
    for(int i=0;i<n;i++){
      if(h.at(i)!=0){
        if(i==n-1){
          cout<<ans+h.at(n-1)<<endl;
          return 0;
        }
        l=i;
        mini=h.at(l);
        break;
      }
      if(i==n-1){
        cout <<ans<<endl;
        return 0;
      }
    }
    for(int i=l+1;i<n;i++){
      if(h.at(i)!=0){
        mini=min(mini,h.at(i));
      }
      if(h.at(i)==0){
        r=i;
        break;
      }
      if(i==n-1){
        r=n;
      }
    }
    for(int i=l;i<r;i++){
      h.at(i)-=mini;
    }
    ans+=mini;
  }
}