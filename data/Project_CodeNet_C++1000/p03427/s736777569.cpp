#include<bits/stdc++.h>
using namespace std;
long long dsum(long long n){
  if(n==0) return 0;
  else return n%10+dsum(n/10);
}
int main(){
  long long n,i,k = 10,s;cin >> n;
  long long ans = dsum(n);
  while(n>=k){
    s = n/k*k-1;
    ans = max(ans,dsum(s));
    k *= 10;
  }
  cout << ans << "\n";
}