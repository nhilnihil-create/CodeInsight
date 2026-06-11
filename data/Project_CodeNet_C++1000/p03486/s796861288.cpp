#include<bits/stdc++.h>
using namespace std;
int main(){
  string s,t;
  cin>>s>>t;
  int size=min(s.size(),t.size());
  sort(s.begin(),s.end());sort(t.rbegin(),t.rend());
  for(int i=0;i<size;i++){
    if(s.at(i)>t.at(i)){
      cout <<"No"<<endl;
      return 0;
    }
    else if(s.at(i)<t.at(i)){
      cout <<"Yes"<<endl;
      return 0;
    }
  }
  if(s.size()>=t.size()){
    cout <<"No"<<endl;
    return 0;
  }
  else{
    cout <<"Yes"<<endl;
  }
}