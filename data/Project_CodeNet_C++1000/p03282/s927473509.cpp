#include<bits/stdc++.h>
#define rep(i,f,n) for(ll i=(f); (i) < (n); i++)
#define repe(i,f,n) for(ll i=(f); (i) <= (n); i++)
using namespace std;

typedef long long ll;
ll INF = 1LL << 60;
ll MAX = 100010;
ll MOD = 2019;

int
main() 
{

  string S; cin >> S;
  ll K; cin >> K;
  string ans;
  if(S.size() > K){
    rep(i, 0, K){
      ans = S[i];
      if(S[i] != '1') break;
    }
  } else {
    rep(i, 0, S.size()){
      ans = S[i];
      if(S[i] != '1')break;
    }
  }
  cout << ans << endl;
}

