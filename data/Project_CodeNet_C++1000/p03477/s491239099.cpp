#include <bits/stdc++.h>
using namespace std;
const int64_t INF=999999999;

int main() {
   int A,B,C,D;
   cin>>A>>B>>C>>D;
   if(A+B>C+D){cout<<"Left"<<endl;}
   if(A+B==C+D){cout<<"Balanced"<<endl;}
   if(A+B<C+D){cout<<"Right"<<endl;}
return 0;}