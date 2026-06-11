#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i < (ll)(n); i++)
#define INF 10000000000
#define MAX 1000010
#define MOD 1000000007
  
using ll = long long;
using Graph = vector<vector<pair<ll,ll>>>;

int main(){
  ll N,K; cin>>N>>K;
  ll res = 0;
  for(ll b = 1; b <= N; b++){
    ll r = N%b;
    ll p = N/b;
    res += p*max((ll)0,b-K)+max((ll)0,r-K+1);
    if(K==0)res--;
  }
  cout<<res<<endl;
}