#include<bits/stdc++.h>
using namespace std;
int main(){
  string S;
  cin>>S;
  int k0=0,k1=0;
  for(char c:S){
    if(c=='0')
      k0++;
    else
      k1++;
  }
  cout<<min(k0,k1)*2<<endl;
}