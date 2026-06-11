#include <bits/stdc++.h>
using namespace std;
const int64_t INF=9999999999999999;

int main() {
   int A,B,C;
   cin>>A>>B>>C;
   int ma=max({A,B,C});
   if((3*ma-(A+B+C))%2==0){cout<<(3*ma-(A+B+C))/2<<endl;}
   else{cout<<(3*(ma+1)-(A+B+C))/2<<endl;}
return 0;}