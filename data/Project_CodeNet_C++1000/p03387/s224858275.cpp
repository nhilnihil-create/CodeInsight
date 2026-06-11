#include <bits/stdc++.h>
using namespace std;






int main(){
  


  vector<int> vec(3);
  
  int a,b,c;
  cin>>a>>b>>c;
  
  vec.at(0)=a;
  vec.at(1)=b;
  vec.at(2)=c;
  
  sort(vec.begin(),vec.end());
  reverse(vec.begin(),vec.end());
  
  a=vec.at(0);
  b=vec.at(1);
  c=vec.at(2);
  
  int answer=0;
  


  if ((b-c)%2==0){
    answer=(2*a-b-c)/2;
  }
  
  else {
    answer=((2*a-b-c)/2)+2;
  }
  
  cout<<answer<<endl;
  
  
    
    
  


    
  
  
  
}