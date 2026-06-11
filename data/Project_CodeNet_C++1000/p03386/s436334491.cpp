#include <bits/stdc++.h>
using namespace std;
const int INF=999999999;

int main() {
 int A,B,K;
 cin>>A>>B>>K;
 map<int,int>x;
 for(int i=A;i<min(B+1,A+K);i++){
     x[i]++;
     cout<<i<<endl;
 }
 for(int i=max(A,B-K+1);i<=B;i++){
     if(x[i]>0){continue;}
     cout<<i<<endl;
 }

 return 0;}