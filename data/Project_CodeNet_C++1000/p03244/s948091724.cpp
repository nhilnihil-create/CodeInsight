#include <bits/stdc++.h>
#define vsort(v) sort(v.begin(), v.end())
#define rvsort(v) sort(v.begin(), v.end(), greater<pair<ll, ll>>())
#define ll long long
#define rep(i, s, g) for (ll i = (s); i < (g); i++)
#define MOD 1000000007
#define vfind(v, target) find(v.begin(), v.end(), target)
#define notFound(v, target) (vfind(v, target) == v.end())

using namespace std;

int main()
{
  ll N, ans; cin >> N;
  vector<ll> V(N);
  rep(i, 0, N) {
  	cin >> V[i]; V[i]--;
  }
  vector<pair<ll, ll>> odd(100005), even(100005);
  rep(i, 0, 100005) {
  	odd[i] = make_pair(0, i);
    even[i] = make_pair(0, i);
  }
  rep(i, 0, N) {
  	if (i % 2) {
    	odd[V[i]].first++;
    } else {
    	even[V[i]].first++;
    }
  }
  rvsort(odd);
  rvsort(even);
  if (odd[0].second != even[0].second) {
    ans = N - odd[0].first - even[0].first;
  } else {
  	ans = min(N - odd[0].first - even[1].first, N - odd[1].first - even[0].first); 
  }
  cout << ans << endl;
}