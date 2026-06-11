#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,a,b;
  cin>>n>>a>>b;
  if(n*a>=b){
    cout<<b<<'\n';
  }
  else{
    cout<<n*a<<'\n';
  }
  return 0;
}
