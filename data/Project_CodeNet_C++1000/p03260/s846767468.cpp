#include <bits/stdc++.h>
using namespace std;
const int64_t INF=999999999;

int main() {
   int A,B,C;
   cin>>A>>B;
   for(int i=0;i<=3;i++){
      C=i;
      if(A*B*C%2!=0){cout<<"Yes"<<endl;return 0;}
   }
   cout<<"No"<<endl;
return 0;}