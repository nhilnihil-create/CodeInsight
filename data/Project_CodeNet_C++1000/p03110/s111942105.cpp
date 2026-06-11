#include <bits/stdc++.h>
using namespace std;
#include <math.h>
const int64_t INF=9999999999999999;
int main() {
 double N,x;
 string u;
 cin>>N;
 double sum=0;
 
 while(cin>>x>>u){
     if(u=="JPY"){sum+=x;}
     else{sum+=x*380000.0;}
 }
 cout<<fixed<<setprecision(9)<<sum<<endl;
 return 0;}