#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<int> x(4,0);
  for(int i=0;i<3;i++){
    int a,b;
    cin>>a>>b;
    a--;b--;
    x.at(a)++;
    x.at(b)++;
  }
  
  bool flag=true;
  for(int i=0;i<4;i++){
    if(x.at(i)==3){
      flag=false;
    }
  }
  
  if(flag){
    cout<<"YES"<<endl;
  }else{
    cout<<"NO"<<endl;
  }
}