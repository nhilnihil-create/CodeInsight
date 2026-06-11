#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  string s;
  cin >> n >> k >> s;
  vector<int> seq;
  if (s.at(0) == '0') seq.push_back(0);
  int seq_count = 1;
  for (int i = 1; i < n; i++) {
    if (s.at(i) == s.at(i - 1)) {
      seq_count++;
    } else {
      seq.push_back(seq_count);
      seq_count = 1;
    }
  }
  seq.push_back(seq_count);
  if (seq.size() % 2 == 0) seq.push_back(0);
  int count = seq.at(0), ans;
  for (int i = 0; i < k; i++) {
    if (2 * i + 2 >= seq.size()) {
      cout << count << endl;
      return 0;
    }
    count += seq.at(2 * i + 1) + seq.at(2 * i + 2);
  }
  ans = count;
  for (int i = k; 2 * i + 2 < seq.size(); i++) {
    count += seq.at(2 * i + 1) + seq.at(2 * i + 2);
    count -= seq.at(2 * (i - k)) + seq.at(2 * (i - k) + 1);
    ans = max(ans, count);
  }
  cout << ans << endl;
}
