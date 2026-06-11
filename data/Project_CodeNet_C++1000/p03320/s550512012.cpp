#include <bits/stdc++.h>

using namespace std;

#define REP(i,m) for(int i=0; i<m; i++)
#define FOR(i,n,m) for(int i=n; i<m; i++)
#define INF 1000000001
#define INFL (1LL << 60)
#define MOD 998244353
#define ALL(v) v.begin(),v.end()
#define pb push_back
#define ll long long int
#define P pair<int, int>

ll S(ll n){
  if(n<10) return n;
  else return (S(n/10) + (n%10));
}

int main(){
  ll pt = 1;
  vector<ll> ans;
  REP(i, 16){
    ll x = 2;
    while((x*pt-1)*S(x*pt+pt-1) <= (x*pt+pt-1)*S(x*pt-1)){
      ans.pb(x*pt-1);
      x++;
    }
    pt *= 10LL;
  }
  sort(ALL(ans));
  REP(i, ans.size()-1){
    if(ans[i] == ans[i+1]){
      ans.erase(ans.begin()+i);
      i--;
    }
  }
  int p;
  cin >> p;
  REP(i, p) cout << ans[i] << endl;
}
