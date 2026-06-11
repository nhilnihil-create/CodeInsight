#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,n,m;
  cin>>a>>b;
  n = a / 500;
  m = a % 500;
  if(a-n*500 > b){
    cout<<"No"<<'\n';
  }
  else{
    cout<<"Yes"<<'\n';
  }
}

