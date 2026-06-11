#include<iostream>
#include<algorithm>
using namespace std;
int main(){

  vector<int>num(3);
  cin>>num[0]>>num[1]>>num[2];
  sort(num.begin(),num.end());
  int time=0;
  while(num[0]<=num[2]-2){
  
    num[0]+=2;
    time++;
  }
  while(num[1]<=num[2]-2){
  
    num[1]+=2;
    time++;
  }
  if(num[0]==num[1]){
  
    if(num[1]==num[2])time;
    else time++;
  }
  else{
  
    time+=2;
  }
  cout<<time;
  return 0;
}