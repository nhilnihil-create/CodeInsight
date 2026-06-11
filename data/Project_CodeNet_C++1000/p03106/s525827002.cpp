#include <bits/stdc++.h>
using namespace std;
#include <math.h>
const int64_t INF=9999999999999999;
int main() {
 int A,B,K;
 cin>>A>>B>>K;
 vector<int>y;
 for(int i=1;i<=100;i++){
     if(A%i==0&&B%i==0){y.push_back(i);}}
  cout<<y[y.size()-K]<<endl;
 
 return 0;}