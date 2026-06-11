#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,A,B;
  cin>>N>>A>>B;
  1<=N<=20;
  1<=A<=100;
    1<=B<=2000;
  if(N*A<=B){
    cout<<N*A;
  }else{
    cout<<B;
  }
}