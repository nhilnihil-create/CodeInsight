#include <bits/stdc++.h>
using namespace std;
int func(int x){
  int sum=0;
  for(int i=0;i<to_string(x).size();i++)
    sum+=to_string(x).at(i)-'0';
  return sum;
}
int main(){
  int A,B,N;
  cin>>N>>A>>B;
  int count=0;
  for(int i=1;i<N+1;i++){
    if(A<=func(i) && B>=func(i)){
      count+=i;
    }  
  }
  cout<<count<<endl;
}