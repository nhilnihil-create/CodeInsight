#include<bits/stdc++.h>
int n,x,y,h,w,res;
using namespace std;
int main(){
  cin>>n>>h>>w;
  while(n--){
   cin>>x>>y;
   if(x>=h&&y>=w) res++;
}
  cout<<res;
  return 0;
}