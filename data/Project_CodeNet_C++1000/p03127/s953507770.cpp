#include <bits/stdc++.h>
using namespace std;
signed gcd(long long x, long long y) {
    if (y == 0)return x;
    return gcd(y, x % y);
}
int main(){
  int N; cin>>N;
  long long ans=0;
  for(int i=0;i<N;i++){
    long long a; cin>>a;
    ans=gcd(a,ans);
  }
  cout<<ans<<endl;
}