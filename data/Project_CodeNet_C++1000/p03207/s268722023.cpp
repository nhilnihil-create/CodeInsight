#include <bits/stdc++.h>
using namespace std;
#include <math.h>
const int64_t INF=9999999999999999;
int main() {
 int N;
 cin>>N;
 vector<int>p(N);
 for(int i=0;i<N;i++){
     cin>>p[i];
 }
 sort(p.begin(),p.end());
 p[N-1]/=2;
 int sum=0;
 for(int i=0;i<N;i++){
     sum+=p[i];
 }
 cout<<sum<<endl;
 return 0;}