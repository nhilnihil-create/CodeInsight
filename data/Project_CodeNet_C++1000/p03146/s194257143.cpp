#include <bits/stdc++.h>
using namespace std;
int func(int x){
  if(x%2==0){
  return x/2;
  }
  return 3*x+1;
}
int main(){
int S;
cin>>S;
vector<int> a(1,S);  
bool b=false; 
int count=0,i=0;
  while(b==false){
    i=func(a.at(count));
    for(int x:a){
      if(x==i){
        cout<<a.size()+1<<endl;
        b=true;
        
      }
    }
    a.push_back(i);
    count++;

   
  }
  for(int i=0;i<a.size();i++){

  }
  
}