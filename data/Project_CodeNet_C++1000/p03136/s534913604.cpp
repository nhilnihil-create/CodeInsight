#include <bits/stdc++.h>
using namespace std;
const int64_t INF=999999999;

int main() {
   int N;
   cin>>N;
   vector<int>L(N);
   int sum=0;
   for(int i=0;i<N;i++){
      cin>>L[i];
      sum+=L[i];
   }
   sort(L.begin(),L.end());
   if(L[L.size()-1]<sum-L[L.size()-1]){cout<<"Yes"<<endl;}
   else{cout<<"No"<<endl;}
return 0;}