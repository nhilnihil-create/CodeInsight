#include<bits/stdc++.h>
using namespace std;
int main(){
  string s,t;
  cin>>s>>t;
  for(int i=0;i<s.size();i++){
    bool f=1;
    for(int j=0;j<s.size();j++)
      if(s.at((i+j)%s.size())!=t.at(j))
        f=0;
    if(f){
      cout<<"Yes"<<endl;
      return 0;
    }
  }
  cout<<"No"<<endl;
}