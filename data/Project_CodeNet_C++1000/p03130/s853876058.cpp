#include <bits/stdc++.h>
using namespace std;

int main(){
  map<int,int> mp;
  int temp;
  for(int i=0;i<6;i++){
    cin>>temp;
    temp--;
    mp[temp]++;
  }
  if(mp.size()==3){
    cout<<"NO"<<endl;
    return 0;
  }
  for(int i=0;i<4;i++){
    if(mp[i]>=3){
      cout<<"NO"<<endl;
      return 0;
    }
  }
  
    
    
  cout<<"YES"<<endl;
  
  return 0;
}

    
  
  