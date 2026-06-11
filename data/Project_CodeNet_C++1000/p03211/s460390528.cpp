#include <bits/stdc++.h>
using namespace std;

int main(){
  int64_t S;
  cin>>S;
  int64_t j=753;
  for(int64_t i=0;i<to_string(S).size()-2;i++){
    j=min(j,abs(753-S%(int64_t)pow(10,i+3)/(int64_t)pow(10,i)));
  }
  cout<<j<<endl;
}