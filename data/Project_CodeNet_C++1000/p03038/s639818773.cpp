#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<ll, ll> P;
ll Mod = 1000000007;
int main() {
  ll N,M;
  cin >> N >> M;
  vector<ll> A(N);
  vector<P> Card(M);
  for (int i = 0; i < N; i++ ){
    cin >> A[i];
  }
  ll sum = 0;
  for (int i = 0; i < M; i++) {
    cin >> Card[i].second >> Card[i].first;
    sum += Card[i].second;
  }
  sort(Card.begin(),Card.end());
  reverse(Card.begin(),Card.end());
  int cnt = 0;
  for (int i = 0; i < N; i++) {
    A.push_back(Card[cnt].first);
    Card[cnt].second--;
    if (Card[cnt].second == 0) {
      cnt++;
    }
    if (i == sum - 1) {
      break;
    }
  }
  sort(A.begin(),A.end());
  reverse(A.begin(),A.end());
  ll ans = 0;
  for (int i = 0; i < N; i++) {
    ans += A[i];
  }
  cout << ans << endl;
  return 0;
}
