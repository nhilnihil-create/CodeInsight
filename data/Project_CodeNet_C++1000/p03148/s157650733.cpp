#include <bits/stdc++.h>

using namespace std;

const int nmax = 1e9 + 7;
const long long INF = 1e18;
const double PI = 2 * asin(1);
typedef long long ll;


int main(){
  ll N, K; cin >> N >> K;
  vector < pair<ll, int> > DT(N);
  
  for (int i = 0; i < N; i++){
    int T, D; cin >> T >> D; T--;
    DT[i] = make_pair(D, T);
  }
  sort(DT.begin(), DT.end(), greater< pair<ll, int> > ());

  vector <int> cnt(N);
  ll ans = 0, X = 0;
  priority_queue < pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int> > > que;

  for (int i = 0; i < K; i++){
    que.push(DT[i]);
    ans += DT[i].first;
    if (cnt[DT[i].second] == 0) X++;
    cnt[DT[i].second]++;
  }
  ans += X * X;

  ll now = ans;
  for (int i = K; i < N; i++){
    if (cnt[DT[i].second] == 0){
      while (!que.empty()){
        pair <ll, int> P = que.top(); que.pop();

        if (cnt[P.second] > 1){
          now += DT[i].first - P.first;
          now += (X + 1) * (X + 1) - X * X;
          X++; cnt[P.second]--;
          cnt[DT[i].second]++;
          break;
        }
      }
      ans = max(now, ans);
    }
  }
  
  cout << ans << endl;
  
  return 0;
}
