#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    a[i] -= i + 1;
  }
  sort(a.begin(), a.end());
  long long sum = 0;
  for (long long i = 1; i < n; i++) {
    a[i] -= a[0];
    sum += a[i];
  }
  a[0] = 0;
  priority_queue<long long, vector<long long>, greater<long long>> pq;
  pq.push(sum);
  long long cnt = 1;
  for (long long i = 1; i < n; i++) {
    if (a[i] == a[i - 1]) {
      cnt++;
      continue;
    }
    sum += i * (a[i] - a[i - 1]);
    sum -= (n - i) * (a[i] - a[i - 1]);
    pq.push(sum);
  }
  cout << pq.top() << endl;
}