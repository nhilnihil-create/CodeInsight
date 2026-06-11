#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll Mod = 1000000007;
int main() {
  int n;
  cin >> n;
  int v[n];
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  vector<pair<int,int>> P1(100001);
  vector<pair<int,int>> P2(100001);
  for (int i = 0; i < 100001; i++) {
    P1[i].first = 0;
    P1[i].second = i;
    P2[i].first = 0;
    P2[i].second = i;
  }
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) {
      P1[v[i]].first++;
    } else {
      P2[v[i]].first++;
    }
  }
  sort(P1.begin(),P1.end());
  reverse(P1.begin(),P1.end());
  sort(P2.begin(),P2.end());
  reverse(P2.begin(),P2.end());
  int ans = 0;
  if (P1[0].second != P2[0].second) {
    ans = n - P1[0].first - P2[0].first;
  } else {
    ans = min(n - P1[1].first - P2[0].first,n - P1[0].first - P2[1].first);
  }
  cout << ans << endl;
  return 0;
}