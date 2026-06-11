#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int n, m;
  cin >> n >> m;
  vector<pair <int, pair<int,int>>> a(m);
  for (int i = 0; i < m; i++) {
      cin >> a[i].second.first >> a[i].first;
      a[i].second.second = i;
  }
  sort(a.begin(), a.end());
  map<int, int> pref_cnt;
  vector<pair<int, int>> pref_city(m);
  for (int i = 0; i < m; i++) {
      int pref = a[i].second.first;
      int city = ++pref_cnt[pref];
      int index = a[i].second.second;
      pref_city[index].first = pref;
      pref_city[index].second = city;
  }
  for (auto &i : pref_city) {
      printf("%06d%06d\n", i.first, i.second);
  }
  return 0;
}
