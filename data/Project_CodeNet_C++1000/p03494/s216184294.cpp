#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef long long ll;
const ll M=1000000000;
//------------------------------------------//

int main(){
  int N;cin>>N;
  int A[210];
  rep(i,N) cin>>A[i];
  
  int ans=0;
  bool flag=true;
  while(flag){
    rep(i,N){
      if(A[i]%2==1){
        flag=false;
        break;
      }
      A[i]/=2;
    }
    ans++;
  }
  cout<<ans-1<<endl;
}
  