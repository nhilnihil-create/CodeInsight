#include <bits/stdc++.h>
using namespace std;
 
int main(){
  long int A,B,C;
  cin>>A>>B>>C;
  long count=0;
  if(C>=A+B+1){
    count+=A+B+1+B;
  }
  else{
    count+=B+C;
  }
  cout<<count;
  return 0;
}