#include<iostream>
#include<map>
using namespace std;
 
int main() {
  long long n, m, current, f, s;
  map<long long, long long> memo;
  long long sum = 0, ans = 0;
  scanf("%lld %lld", &n, &m);
  for (long long i=0; i<n; i++) {
    scanf("%lld", &current);
    sum += current;
    if (memo.find(sum % m) == memo.end()) {
      memo[sum % m] = 0;
    }
    memo[sum % m]++;
  }
  for (map<long long, long long>::iterator it = memo.begin(); it != memo.end(); ++it) {
    f = it->first;
    s = it->second;
    if (s > 1) ans += (s*(s-1)/2);
    if (f == 0) ans += s;
  }
  cout << ans << endl;
  return 0;
}