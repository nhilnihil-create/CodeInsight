#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<ll, ll> P;

int main(){
  int n, m; scanf("%d %d", &n, &m);
  vector<ll> a(n);
  ll ans = 0;
  for(int i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
    ans += a[i];
  }
  sort(a.begin(), a.end());

  vector<P> data(m);
  for(int i = 0; i < m; i++){
    scanf("%lld %lld", &data[i].second, &data[i].first);
  }
  sort(data.begin(), data.end(), greater<P>());

  int now = 0, sum = 0;
  for(int i = 0; i < n; i++){
    if(data[now].first > a[i]){
      ans += (data[now].first - a[i]);
      sum++;
    }
    if(sum == data[now].second){
      sum = 0;
      now++;
    }
  }
  printf("%lld\n", ans);
}