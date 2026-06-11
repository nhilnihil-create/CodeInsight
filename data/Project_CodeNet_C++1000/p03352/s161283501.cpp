#include<bits/stdc++.h>
using namespace std;

int main(){
  int X;cin>>X;
  int l=0;
  while(true){
    if((l+1)*(l+1)<=X) l++;
    else break;
  }
  priority_queue<int> A;
  A.push(1);
  for(int i=2;i<=l;i++){
    int j=i*i;
    while(true){
      if(j<=X){
        A.push(j);
        j*=i;
      }
      else break;
    }
  }
  cout<<A.top()<<endl;
}