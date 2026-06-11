#include <bits/stdc++.h>
using namespace std;
const int64_t INF=999999999;

int main() {
   int a,b,c,d;
   cin>>a>>b>>c>>d;
   if(abs(a-c)<=d||abs(b-a)<=d&&abs(c-b)<=d){cout<<"Yes"<<endl;}
   else{cout<<"No"<<endl;}
return 0;}