#include <bits/stdc++.h>
using namespace std;



int main(){
  int A,B,C;
  cin>>A>>B>>C;
  
  vector<int> vec(3);
  vec.at(0)=A;
  vec.at(1)=B;
  vec.at(2)=C;
  sort(vec.begin(),vec.end());
  
  int sum=0;
  while(vec.at(0)<=vec.at(2)-2){
    sum++;
    vec.at(0)+=2;
  }
  while(vec.at(1)<=vec.at(2)-2){
    sum++;
    vec.at(1)+=2;
  }
  if(vec.at(0)==vec.at(2)-1&&vec.at(1)==vec.at(2)) sum+=2;
  else if(vec.at(0)==vec.at(2)&&vec.at(1)==vec.at(2)-1) sum+=2;
  else if(vec.at(0)==vec.at(2)-1&&vec.at(1)==vec.at(2)-1) sum+=1;
  
  cout<<sum<<endl;
    
  
}