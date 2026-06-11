#include<bits/stdc++.h>
using namespace std;
int main(){
string S;
  cin>>S;
  int count=700;
  for(int i=0;i<S.size();i++){
  if(S.at(i)=='o'){
  count+=100;
  
  }
    if(S.at(i)=='x'){
    count+=0;
    }
  
  }
cout<<count<<endl;
}