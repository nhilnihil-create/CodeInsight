#include <bits/stdc++.h>
#define M0D 1000000007
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;

int main(){

  long N,K;
  cin >> N >> K;
  long ans=0;
  for(int j=K+1; j<=N; j++){
      ans += (N/j)*(j-K)+max((long)0,(N-j*(N/j))-K+1);
  }
  if(K==0) ans = N*N;
  cout << ans << endl;

  return 0;
}
