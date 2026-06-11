#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin>>S;
  vector<char> p={};
  for(int i=0;i<S.size();i++){
    if(S.at(i)!='x'){
      p.push_back(S.at(i));
    }
  }
  if(1==0){
    cout<<"-1"<<endl;
  }
  else{
    int Z=0;
    for(int i=0;i<p.size()/2;i++){
      if(p.at(i)!=p.at(p.size()-1-i)){
        Z++;
        break;
      }
    }
    if(Z==1){
      cout<<"-1"<<endl;
    }
    else{
      vector<int>q(p.size()+1);
      int a=0;
      for(int i=0;i<S.size();i++){
        if(S.at(i)=='x'){
          q.at(a)++;
        }
        else{
          a++;
        }
      }
      for(int i=0;i<q.size()/2;i++){
        Z+=abs(q.at(i)-q.at(p.size()-i));
      }
      cout<<Z<<endl;
    }
  }
          
}