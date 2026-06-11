#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,red=0; cin>>n;
  for(int i=0;i<n;i++){
    char a; cin>>a;
    if(a=='R')red++;
  }
  
  cout<<(red > n-red ? "Yes" : "No")<<endl;
  return 0;
}