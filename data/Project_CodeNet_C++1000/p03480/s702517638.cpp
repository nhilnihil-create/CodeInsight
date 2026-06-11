#include <bits/stdc++.h>
using namespace std;

string s;
vector<long long> v;

long long solve();
bool ch(long long k);

int main() {
  cin >> s;

  cout << solve() << endl;
  return 0;
}

long long solve() {
  long long ans = 10000000000;
  for(int i = 0; i < s.size(); ++i) {
    long long cnt = 1;
    while(i + 1 < s.size() && s[i] == s[i + 1]) ++cnt, ++i;
    v.push_back(cnt);
  }
  for(int i = 1; i < v.size(); ++i) v[i] += v[i - 1];
  for(int i = 0; i < v.size(); ++i)
    ans = min(ans, max(v[i], (long long)s.size() - v[i]));
  return ans;
}