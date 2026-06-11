#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPLL(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

// ABC103 D - Islands War

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, M; cin >> N >> M;
  vector<pair<int, int> > ab(M, pair<int, int>());
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int> > > pq;
  REP(i, M){
    int a, b; cin >> a >> b;
    ab[i] = {a, b};
  }
  sort(ab.begin(), ab.end());
  vector<int> a(M, 0);
  REP(i, M){
    pq.push({ab[i].second, i});
    a[i] = ab[i].first;
  }
  int ans = 0, idx = -1;
  while(!pq.empty()){
    auto cur = pq.top(); pq.pop();
    if(cur.second <= idx) continue;
    auto itr = upper_bound(a.begin(), a.end(), cur.first-1);
    itr--;
    idx = itr-a.begin();
    ans++;
  }
  cout << ans << endl;
}