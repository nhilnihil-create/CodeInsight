#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long int li;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef pair<ll, ll>P;
#define PI 3.14159265359
#define MOD 998244353
const int MAX = 510000;

int main() {
  ll N,K;cin>>N>>K;
  vector<ll>memo(N);
  rep(i,N){
  	ll p;cin>>p;
    p--;
    memo[p]++;
  }
  sort(memo.begin(),memo.end());
  ll ans=0;
  for(int i=0;i<=N-K-1;i++){ans+=memo[i];}
  cout<<ans;
}