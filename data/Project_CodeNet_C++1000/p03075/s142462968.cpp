#include <bits/stdc++.h>
using namespace std;
const int64_t INF=999999999;

int main() {
   int a,b,c,d,e,k;
   cin>>a>>b>>c>>d>>e>>k;
   if(max({a,b,c,d,e})-min({a,b,c,d,e})>k){cout<<":("<<endl;}
   else{cout<<"Yay!"<<endl;}
   
return 0;}