#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef long long ll;
const ll M=1000000007;
//------------------------------------------//

int main(){
  int N,X;cin>>N>>X;
  vector<int> m(N);
  int cnt=0;
  rep(i,N){
    cin>>m[i];
    cnt+=m[i];
  }
  int ans=N;
  X-=cnt;
  sort(m.begin(),m.end());
  ans+=X/m[0];
  cout<<ans<<endl;
}
  