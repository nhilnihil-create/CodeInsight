#include <bits/stdc++.h>
using namespace std;
const int64_t INF=999999999;

int main() {
   int A,B,C;
   cin>>A>>B>>C;
   int sum=A+B+C;
   int x=max({A,B,C});
   int y=min({A,B,C});
   int z=sum-x-y;
   cout<<10*x+y+z<<endl;
return 0;}