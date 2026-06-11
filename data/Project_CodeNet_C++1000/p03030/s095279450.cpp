#include <bits/stdc++.h>
using namespace std;

using pa = pair<string, int>;

int main() {
  int N;
  cin >> N;
  vector<pair<pa,int>> a(N);
  for (int i = 0; i < N; ++i) {
    cin >> a[i].first.first >> a[i].first.second;
    a[i].first.second *= -1;
    a[i].second = i;
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < N; ++i) {
    cout << a[i].second + 1 << endl;
  }
}
  