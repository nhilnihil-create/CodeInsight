#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a.at(i);
  }
  vector<int> bucket(200001, 0);
  for (int i = 0; i < n; i++) {
    bucket.at(a.at(i))++;
  }

  if (bucket.size() <= k) {
    cout << 0 << endl;
    return 0;
  } else {
    sort(bucket.begin(), bucket.end());
    int ball = bucket.size() - k;
    int count = 0;
    for (int i = 0; i < ball; i++) {
      count += bucket.at(i);
    }
    cout << count << endl;
    return 0;
  }
}