#include<bits/stdc++.h>
#define rep(i,f,n) for(ll i=(f); (i) < (n); i++)
#define repe(i,f,n) for(ll i=(f); (i) <= (n); i++)
using namespace std;
using ll = long long;

ll INF = 1LL << 60;

int 
main() {

  int N; cin >> N;
  vector<ll> arr(N);
  rep(i, 0, N) cin >> arr[i];
  vector<ll> acum(N + 1, 0);
  rep(i, 0, N) acum[i + 1] = acum[i] + arr[i];

  map<ll, ll> ans;
  rep(i, 0, N + 1){
    ans[acum[i]]++;
  }

  ll sum = 0;
  for(auto x: ans){
    ll num = x.second;
    sum += num * (num - 1) / 2;
  }
 
  cout << sum << endl;

}
