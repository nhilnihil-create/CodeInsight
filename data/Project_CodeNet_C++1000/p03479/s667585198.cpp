#include<bits/stdc++.h>
using namespace std;

int main(){
  
  long long X, Y, cnt=0;
  cin>>X>>Y;
  
  while(X<=Y){
    X*=2;
    cnt++;
  }
  cout<<cnt<<endl;
  return 0;
}