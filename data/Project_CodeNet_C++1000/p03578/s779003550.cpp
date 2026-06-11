#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define puts(i) cout << i << endl
#define INF INT_MAX;
#define INFL LLONG_MAX;
typedef long long ll;
using namespace std;

int main(void){
  ll n; cin >> n;
  map<ll,ll> q1;
  rep(i,n){
    ll x; cin >> x;
    q1[x]++;
  }
  ll m; cin >> m;
  map<ll,ll> q2;
  rep(i,m){
    ll x; cin >> x;
    q2[x]++;
  }

  bool ans = true;

  for(auto q : q2){
    if(q1[q.first]<q.second) ans = false;
  }

  if(ans) puts("YES");
  else puts("NO");

}
