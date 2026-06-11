#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define numrep(i,n) for(int i=1;i<=n;i++)
#define bitrep(n) for(int bit=0;bit<(1<<n);bit++)
#define ll int64_t
#define all(v) v.begin(), v.end()

const int MOD = 1000000007;

int main() {

ll N,ans; cin>>N;

set<ll> S;

S.insert(N);

for(int i=2;;i++){
  if(N%2==0) N/=2;

  else N=3*N+1;

  if(S.count(N)){
    ans=i; break;
  }

  S.insert(N);
}
  
cout << ans << endl;

return 0;
}