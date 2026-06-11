#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,j=0;
  cin>>N;
  for(int i=0;i<N;i++){
    int a;
    cin>>a;
    for(;a%2==0;a/=2)
      j++;
  }
  cout<<j<<endl;
}