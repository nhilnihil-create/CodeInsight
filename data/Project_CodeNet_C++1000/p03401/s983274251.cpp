#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
int main(){
  ll N;cin>>N;
  vector<ll> A(N+2,0);rep(i,N)cin>>A[i+1];
  ll ans=0;
  rep(i,N+1){
    ans += abs(A[i+1]-A[i]);
  }
  rep(i,N){
    cout << ans - (abs(A[i+1]-A[i])+abs(A[i+2]-A[i+1])-abs(A[i+2]-A[i])) << endl;
  }
}