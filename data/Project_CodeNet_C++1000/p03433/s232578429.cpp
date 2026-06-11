#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,A;
  cin>>N>>A;
  int X;
  X = N-A;
  if(N<A||N%500<=A||N%500==0){
      cout<<"Yes"<<endl;
  }else{
      cout<<"No"<<endl;
  }
}