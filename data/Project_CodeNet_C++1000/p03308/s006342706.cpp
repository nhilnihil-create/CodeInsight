#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef long long ll;
const ll M=1000000007;
//------------------------------------------//

int main(){
  int N;cin>>N;
  vector<int> A(N);
  rep(i,N) cin>>A[i];
  sort(A.begin(),A.end());
  cout<<A[N-1]-A[0]<<endl;
}
  