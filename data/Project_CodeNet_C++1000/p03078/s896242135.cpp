#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  vector<int> cntlist(3);
  for (int i = 0; i < 3; i++) {
    cin >> cntlist[i];
  }
  int k;
  cin >> k;

  vector<vector<ll> > vlist(3);
  for (int i = 0; i < 3; i++) {
    vlist[i].resize(cntlist[i]);
    for (int j = 0; j < cntlist[i]; j++) {
      cin >> vlist[i][j];
    }
    sort(vlist[i].begin(), vlist[i].end(), greater<ll>());
  }

  priority_queue<pair<ll, vector<int> > > pq;
  ll v = vlist[0][0] + vlist[1][0] + vlist[2][0];
  vector<int> vec(3, 0);
  pq.push(make_pair(v, vec));

  set<pair<ll, vector<int> > > ss;
  ss.insert(make_pair(v, vec));

  while(k--) {
    if (!pq.empty()) {
      pair<ll, vector<int> > p = pq.top(); pq.pop();
      cout << p.first << endl;
      for (int i = 0; i < 3; i++) {
        if (p.second[i] + 1 < cntlist[i]) {
          ll v = p.first - vlist[i][p.second[i]] + vlist[i][p.second[i] + 1];
          vector<int> vec = p.second;
          vec[i]++;
          pair<ll, vector<int> > np = make_pair(v, vec);
          if (ss.count(np) == 0) {
            pq.push(np);
            ss.insert(np);
          }
        }
      }
    }
  }
  return 0;
}