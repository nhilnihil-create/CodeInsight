#include <bits/stdc++.h>
using namespace std;
const int64_t INF=9999999999999999;

int main() {
   string S;
   cin>>S;
   int count0=0;int count1=0;
   for(int i=0;i<S.size();i++){
      if(S[i]=='0'){count0++;}
      if(S[i]=='1'){count1++;}
   }
   cout<<min(count0,count1)*2<<endl;
return 0;}