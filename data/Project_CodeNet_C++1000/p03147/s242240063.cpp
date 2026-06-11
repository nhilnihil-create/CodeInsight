#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int main() {
  int N;
  cin >> N;
  vector<int> h(N);
  for(int i = 0; i < N; i++){
    cin >> h[i];
  }

  vector<P> group;
  for (int i = 0; i < N; i++)
  {
    if (h[i] == 0) {
      group.push_back(P(i, 1));
      continue;
    }
    int cnt = 1;
    int j = i;
    while (h[i] <= h[i + 1] && i < N - 1)
    {
      cnt++;
      i++;
    }
    group.push_back(P(j, cnt));
  }
  
  int ans = 0;
  bool zero = true;
  for (int i = 0; i < group.size(); i++) {
    if (group[i].second == 1 && h[group[i].first] == 0)
    {
      zero = true;
      continue;
    }
    if (zero)
    {
      ans += h[group[i].first + group[i].second - 1];
      zero = false;
    } else {
      ans += h[group[i].first + group[i].second - 1] - h[group[i].first];
    } 
  }
  cout << ans << endl;
  return 0;
}