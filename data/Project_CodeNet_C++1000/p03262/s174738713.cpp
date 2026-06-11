#include <bits/stdc++.h>
using namespace std;
signed gcd(long long x, long long y) {if (y == 0)return x;return gcd(y, x % y);}
int main(){
  int N,X; cin>>N>>X;
  long long ans;
  vector<int>A(N);
  for(int i=0;i<N;i++){
    cin>>A[i];
    if(i==0)ans=abs(X-A[i]);
    else ans=gcd(ans,A[i]-A[i-1]);
  }
  cout<<ans<<endl;
}