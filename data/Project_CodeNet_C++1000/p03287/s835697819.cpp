#include<iostream>
#include<map>
using namespace std;

int main() {
  long long n, m, current, f, s;
  map<long long, long long> memo;
  memo[0] = 1;
  long long sum = 0, ans = 0;
  scanf("%lld %lld", &n, &m);
  for (long long i=0; i<n; i++) {
    scanf("%lld", &current);
    sum = (sum + current) % m;
    memo[sum]++;
  }
  for (auto it : memo) {
    f = it.first;
    s = it.second;
    cerr << f << " " << s << endl;
    ans += (s*(s-1)/2);
  }
  cout << ans << endl;
  return 0;
}
