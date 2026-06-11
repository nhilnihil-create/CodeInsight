#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

int main(){
  map<int,int> mp;
  for(int i=0;i<3;i++){
    int a;
    cin>>a;
    mp[a]++;
  }
  for(auto p:mp){
    if(p.second==1) cout<<p.first<<endl;
  }
}