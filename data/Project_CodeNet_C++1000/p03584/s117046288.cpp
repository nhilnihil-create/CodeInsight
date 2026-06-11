#include <bits/stdc++.h>
using namespace std;

long long n, k;
long long a[100000], b[100000];
long long ans = 0;
void f(vector<bool> &used, int digit, long long value) {
  if (digit == -1) {
    ans = max(value, ans);
    return;
  }
  int d_k = (k >> digit) & 1;
  if (d_k == 0) {
    set<int> unused;
    for (int i=0; i<n; i++) {
      int d_ai = (a[i] >> digit) & 1;
      if (used[i] && d_ai == 1) {
        unused.insert(i);
        used[i] = false;
        value -= b[i];
      }
    }
    f(used, digit-1, value);
    for (int i: unused) {
      used[i] = true;
    }
  } else {
    set<int> s1;
    for (int i=0; i<n; i++) {
      int d_ai = (a[i] >> digit) & 1;
      if (used[i] && d_ai == 1) {
        s1.insert(i);
      }
    }
    if (s1.size() == 0) {
      ans = max(value, ans);
      return;
    }
    f(used, digit-1, value);
    for (int i: s1) {
      value -= b[i];
    }
    ans = max(value, ans);
  }
}
int main() {
  cin>>n>>k;
  for (int i=0; i<n; i++) cin>>a[i]>>b[i];
  long long sum = 0;
  for (int i=0; i<n; i++) sum += b[i];
  vector<bool> used;
  for (int i=0; i<n; i++) used.push_back(true);
  f(used, 29, sum);
  cout<<ans<<endl;
}