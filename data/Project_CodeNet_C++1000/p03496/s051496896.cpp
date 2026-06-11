#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll INF = 1e9;
const ll MOD = 1e9 + 7;

int main() {
  int N;
  cin >> N;
  ll max_idx = -1;
  ll maxv = -1;
  vector<ll> list(N);
  for (int i = 0; i < N; i++) {
    cin >> list[i];
    if (maxv < abs(list[i])) {
      maxv = abs(list[i]);
      max_idx = i;
    }
  }

  vector<pair<ll, ll> > hist;
  for (int i = 0; i < N; i++) {
    list[i] += list[max_idx];
    hist.push_back(make_pair(max_idx + 1, i + 1));
  }

  if (list[max_idx] >= 0) {
    for (int i = 0; i < N - 1; i++) {
      list[i + 1] += list[i];
      hist.push_back(make_pair(i + 1, i + 2));
    }
  } else {
    for (int i = N - 1; i > 0; i--) {
      list[i - 1] += list[i];
      hist.push_back(make_pair(i + 1, i));
    }
  }

  cout << hist.size() << endl;
  for (auto itr = hist.begin(); itr != hist.end(); itr++) {
    cout << itr->first << " " << itr->second << endl;
  }
  return 0;
}
