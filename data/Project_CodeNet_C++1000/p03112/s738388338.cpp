#include <bits/stdc++.h>
using namespace std;

int a, b, q;
long long s[100010];
long long t[100010];

long long solve1(long long x) {
  auto it = upper_bound(s, s + a, x);
  long long dist1;
  {
    long long y = *it;
    int idx = upper_bound(t, t + b, y) - t;
    dist1 = y - x + min(t[idx] - y, y - t[idx-1]);
  }
  --it;
  long long y = *it;
  int idx = upper_bound(t, t + b, y) - t;
  long long dist2 = x - y + min(t[idx] - y, y - t[idx-1]);
  return min(dist1, dist2);
}
long long solve2(long long x) {
  auto it = upper_bound(t, t + b, x);
  long long dist1;
  {
    long long y = *it;
    int idx = upper_bound(s, s + a, y) - s;
    dist1 = y - x + min(s[idx] - y, y - s[idx-1]);
  }
  --it;
  long long y = *it;
  int idx = upper_bound(s, s + a, y) - s;
  long long dist2 = x - y + min(s[idx] - y, y - s[idx-1]);
  return min(dist1, dist2);
}
void solve(long long x) {
  cout<<min(solve1(x), solve2(x))<<endl;
}

int main() {
  cin>>a>>b>>q;
  s[0] = -1e13;
  s[1] = -1e12;
  t[0] = -1e13;
  t[1] = -1e12;
  for (int i=0; i<a; i++) cin>>s[i+2];
  for (int i=0; i<b; i++) cin>>t[i+2];
  s[a+2] = 1e12;
  s[a+3] = 1e13;
  t[b+2] = 1e12;
  t[b+3] = 1e13;
  a += 4;
  b += 4;
  for (int i=0; i<q; i++) {
    long long x;
    cin>>x;
    solve(x);
  }
}