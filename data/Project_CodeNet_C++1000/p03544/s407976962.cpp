#include<iostream>
using namespace std;
using ll=long long;
int main(){

  ll lucas[87]={};
  lucas[0]=2;
  lucas[1]=1;
  int N;
  cin>>N;
  for(int i=2;i<=N;i++){
  
    lucas[i]=lucas[i-1]+lucas[i-2];
  }
  cout<<lucas[N];
  return 0;
}