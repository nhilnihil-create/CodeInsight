#include <bits/stdc++.h>
using namespace std;

int main() {
  string n;
  cin>>n;
  
  int p=n.size();
  int j=0;
  
  for(int i=0;i<p;i++){
    if(n.at(i)=='o'){
      j++;
    }
  }
  
  if(j+15-p>=8){
    cout<<"YES"<<endl;
  }
  else{
    cout<<"NO"<<endl;
  }

}