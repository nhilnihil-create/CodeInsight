#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  ll n, k;
  cin >> n >> k;
  vector < ll > a(n);
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }

  ll m = 64 - __builtin_clzll(k);

  if(k == 0){
    ll sum = 0;
    for(int i = 0; i < n; i++) sum += a[i];
    cout << sum << endl;
    exit(0);
  }

  vector < pair < ll, ll > > bt(55, {0, 0});
  for(int i = 0; i < 55; i++){
    ll st = 0, nst = 0;
    for(int j = 0; j < n; j++){
      if((a[j] >> i) & 1){
        nst += ((ll)1 << i);
      }else st += ((ll)1 << i);
    }

    bt[i] = {nst, st};
  }

  vector < ll > p(m);
  p[0] = max(bt[0].first, bt[0].second);
  for(int i = 1; i < m; i++){
    p[i] = p[i - 1] + max(bt[i].first, bt[i].second);
  }

  ll ans = LLONG_MIN, sum = 0;
  for(int i = m; i < 55; i++) sum += bt[i].first;
  for(int i = m - 1; i >= 0; i--){
    if((k >> i) & 1){
      if(bt[i].first >= bt[i].second){
        ans = max(ans, sum + p[i]);
      }else{
        sum += bt[i].second;
      }
    }else{
      sum += bt[i].first;
    }
  }
  ans = max(ans, sum);

  cout << ans << '\n';
}
