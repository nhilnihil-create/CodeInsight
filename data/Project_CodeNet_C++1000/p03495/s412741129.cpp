#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  ll N,K;cin>>N>>K;
  vector<ll> A(N);rep(i,N)cin>>A[i];
  vector<ll> cnt(N,0);
  rep(i,N) cnt[A[i]-1]++ ;
  sort(cnt.begin(),cnt.end(),greater<ll>());
  ll ans=0;
  for(int i=K;i<N;++i){
    ans+=cnt[i];
  }
  cout<<ans<<endl;
}