#include <bits/stdc++.h>
using namespace std;
#include <math.h>
const int64_t INF=9999999999999999;
int main() {
 string S;
 cin>>S;
 int count0=0;
 for(int i=0;i<S.size();i++){
    if(S[i]=='0'){count0++;}
 }
 int count1=S.size()-count0;
 cout<<min(count1,count0)*2<<endl;
 return 0;}