#include <bits/stdc++.h>
using namespace std;
int main(){
  signed long long int K,A,B;
  cin>>K>>A>>B;
  unsigned long long int bisket=1;
  for(int i=1;i<=K;i++){
    if(i>=A&&B-A>=2&&i!=K){
      i++;
      bisket+=B-A;
    }
    else bisket++;
  }
  cout<<bisket<<endl;
}