#include <bits/stdc++.h>
using namespace std;
 
int main() {
  vector<int> vec(4);
  for(int i=0;i<4;i++){
    cin>>vec.at(i);
  }
  
  sort(vec.begin(),vec.end());
  
  int p=vec.at(0)*1000+vec.at(1)*100+vec.at(2)*10+vec.at(3);
  
  if(p==1479){
    cout<<"YES"<<endl;
  }
  else{
    cout<<"NO"<<endl;
  }

}