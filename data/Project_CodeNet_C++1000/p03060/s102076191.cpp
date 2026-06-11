#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef long long ll;
const ll M=1000000000;
//------------------------------------------//

int main(){
  int N;cin>>N;
  int V[N];
  int C[N];
  rep(i,N) cin>>V[i];
  rep(i,N) cin>>C[i];
  
  int ans=0;
  rep(i,N){
    if(V[i]>C[i]) ans += V[i]-C[i];
  }
  cout<<ans<<endl;
}