#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const int MAX = 510000;

int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  for (int i=0; i<N; i++) cin >> a[i];
  int sum = accumulate(a.begin(), a.end(), 0);
  double ave = (double)sum/N;
  int ans = 0;
  double dist=abs(a[0]-ave);
  for (int i=1; i<N; i++) {
    if (abs(a[i]-ave)<dist) {
      dist = abs(a[i]-ave);
      ans = i;
    }
  }
  cout << ans << endl;
}