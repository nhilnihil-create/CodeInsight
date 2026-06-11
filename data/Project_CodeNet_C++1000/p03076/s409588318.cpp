#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int a;
  vector<pair<int, int>> v(5);
  int count = 0;
  int sum = 0;
  for(int i=0; i<5; i++) {
    cin >> a;
    sum += a;
    if(a%10 == 0) count++;
    v[i] = make_pair(a%10, a);
  }
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  
  int x;
  for(int i=0; i<4-count; i++) {
    tie(x, ignore) = v[i];
    sum += 10-x;
  }
  cout << sum << endl;
  return 0;
}