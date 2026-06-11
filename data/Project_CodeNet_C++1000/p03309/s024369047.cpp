#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
int main(){
  ll N;cin>>N;
  vector<ll> b(N);
  rep(i,N)cin>>b[i],b[i]=b[i]-(i+1);
  sort(b.begin(),b.end());
  ll m = (b.size()%2==0 ? (b[(N-1)/2+1]+b[(N-1)/2])/2 : b[(N-1)/2]);
  ll ans = 0;
  rep(i,N){
    ans += abs(m-b[i]);
  }
  cout << ans << endl;
}