#include<iostream>
#include<map>
using namespace std;
int main(){
  map<int,int> n;
  int a,b,c;cin>>a>>b>>c;
  n[a]+=1;n[b]+=1;n[c]+=1;
  for(auto& it:n){
    if(it.second==1)cout<<it.first<<endl;
  }
  return 0;
}