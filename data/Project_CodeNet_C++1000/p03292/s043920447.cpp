#include <bits/stdc++.h>
using namespace std;
const int64_t INF=999999999;

int main() {
   int A1,A2,A3;
   cin>>A1>>A2>>A3;
   vector<int>K={A1,A2,A3};
   sort(K.begin(),K.end());
   cout<<K[2]-K[0]<<endl;
return 0;}