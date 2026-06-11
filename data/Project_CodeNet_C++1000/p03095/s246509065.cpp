#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <stack>
#include <utility>
#include <queue>
using namespace std;
typedef long long int lld;
typedef pair<int, int> pii;



int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int bucket[30];
  fill(bucket, bucket+30, 0);
  string st;
  cin >> st;
  for (int i = 0; i < n; ++i) 
    bucket[st[i] - 'a']++;
  lld ans = 1, M = 1000000007;
  for (int i = 0; i < 30; ++i) {
    ans *= bucket[i] + 1;
    ans %= M;
  }
  cout << ans-1 << "\n";
  return 0;
}