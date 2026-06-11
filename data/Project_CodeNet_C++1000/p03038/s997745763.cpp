#include <bits/stdc++.h>
#define vsort(v) sort(v.begin(), v.end())
#define rvsort(v) sort(v.begin(), v.end(), greater<ll>())
#define vfind(v, target) find(v.begin(), v.end(), target)
#define notFound(v, target) (vfind(v, target) == v.end())
#define maxIndex(v) max_element(v.begin(), v.end()) - v.begin()
#define maxElement(v) *max_element(v.begin(), v.end())
#define minIndex(v) min_element(v.begin(), v.end()) - v.begin()
#define minElement(v) *min_element(v.begin(), v.end())
#define ll long long
#define rep(i, s, g) for (ll i = (s); i < (g); i++)
#define MOD 1000000007
using namespace std;

int main()
{
  ll N, M, sum = 0; cin >> N >> M;
  vector<pair<ll, ll>> X(N + M);
  rep(i, 0, N) {
  	ll A; cin >> A;
    X[i] = make_pair(A, 1);
  }
  rep(i, N, N + M) {
  	ll B, C; cin >> B >> C;
    X[i] = make_pair(C, B);
  }
  sort(X.begin(), X.end(), greater<pair<ll, ll>>());
  ll j = 0;
  rep(i, 0, N){
  	sum += X[j].first;
    X[j].second--;
    if (X[j].second <= 0) j++;
  }
  cout << sum << endl;
}