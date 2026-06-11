#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n,sum=0;
  cin>>n;
  for(long long i=1;i*i<=n;i++){
    if(n%i==0 && n/i-1>i) sum+=n/i-1;}
  
  cout<<sum;
  return 0;
}