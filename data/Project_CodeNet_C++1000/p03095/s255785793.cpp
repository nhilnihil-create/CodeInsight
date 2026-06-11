#include<bits/stdc++.h>
using namespace std;
const long P=1000000007;
int main(){
  long N;cin>>N;string S;cin>>S;
  vector<long>A(26,1);
  for(char c:S)A[c-97]++;
  long ans=1;
  for(long x:A)ans=(ans*x)%P;
  cout<<(ans-1+P)%P;
}