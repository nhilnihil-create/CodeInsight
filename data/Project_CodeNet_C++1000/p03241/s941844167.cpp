#include<bits/stdc++.h>
using namespace std;
int main(){
  long long N,M;
  cin>>N>>M;
  vector<long long> A;
  for(long long i=1; i*i<=M; i++){
if(M%i==0) {
  A.push_back(i);
  A.push_back(M/i);
}
}
    sort(A.begin(),A.end());
    reverse(A.begin(),A.end());
    long long t=A.size();
    for(long long i=0; i<t; i++){
if(A[i]<=M/N){ cout<<A[i]<<endl; break;}
    }
  }