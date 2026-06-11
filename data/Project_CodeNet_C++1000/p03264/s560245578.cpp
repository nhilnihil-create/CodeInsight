#include<bits/stdc++.h>
using namespace std;

int main(){
  int k;
  cin>>k;
  int par = 0, imp = 0;
  for(int i = 1; i<=k; ++i){
    if(i&1) imp++;
    else par++;
  }
cout<<par*imp<<"\n";
}