#include <bits/stdc++.h>
using namespace std;
const int64_t INF=999999999;

int main() {
   int A,B,C;
   cin>>A>>B>>C;
   vector<int>K={A,B,C};
   sort(K.begin(),K.end());
   cout<<10*K[2]+K[1]+K[0]<<endl;
return 0;}