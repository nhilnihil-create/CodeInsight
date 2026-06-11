#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t x,y;
  cin>>x>>y;
  int64_t a=x;
  int l=0;
  while(a<=y){
    a*=2;
    l++;
  }
  cout<<l<<endl;
}