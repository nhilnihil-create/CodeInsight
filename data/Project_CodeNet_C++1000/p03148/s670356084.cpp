#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define rep(i,s,e) for(i64 (i) = (s);(i) < (e);(i)++)
#define all(x) x.begin(),x.end()
#define let auto const

int main() {
  i64 N, K;
  cin >> N >> K;
  vector<i64> t(N), d(N);
  vector<pair<i64, i64>> vec;
  rep(i,0,N) {
    cin >> t[i] >> d[i];
    t[i]--;
    vec.push_back({d[i], t[i]});
  }
  sort(all(vec));
  reverse(all(vec));

  vector<vector<i64>> st(N);
  i64 sum = 0;
  i64 cnt = 0;
  rep(i,0,K) {
    sum += vec[i].first;
    st[vec[i].second].push_back(vec[i].first);
    if(st[vec[i].second].size() == 1) {
      cnt++;
    }
  }


  vector<i64> MINs;
  rep(i,0,N) {
    sort(all(st[i]));
    rep(j,0,(i64)st[i].size() - 1) {
      MINs.push_back(st[i][j]);
    }
  }

  sort(all(MINs));
  reverse(all(MINs));

 

  i64 res = sum + cnt * cnt;

  rep(i,K,N) {
    if(MINs.size() == 0) break;
    i64 x = vec[i].first;
    i64 ty = vec[i].second;
    if(st[ty].size() >= 1) continue;
    st[ty].push_back(x);
    i64 y = MINs.back();
    MINs.pop_back();
    sum = sum - y + x;
    cnt++;

    res = max(res, sum + cnt * cnt);


  }

  cout << res << endl;
}
