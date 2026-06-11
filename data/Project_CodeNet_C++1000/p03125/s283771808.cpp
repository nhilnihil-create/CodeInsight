#include <bits/stdc++.h>
using namespace std;
const int64_t INF=9999999999999999;

int main() {
   int A,B;
   cin>>A>>B;
   cout<<(B%A==0?A+B:B-A)<<endl;
return 0;}