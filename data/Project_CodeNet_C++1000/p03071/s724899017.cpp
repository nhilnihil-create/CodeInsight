#include <bits/stdc++.h>
using namespace std;
const int64_t INF=999999999;

int main() {
   int A,B,T;
   cin>>A>>B;
   int ans=0;
   ans+=max(A,B)+ max(max(A,B)-1,min(A,B));
   cout<<ans<<endl;
return 0;}