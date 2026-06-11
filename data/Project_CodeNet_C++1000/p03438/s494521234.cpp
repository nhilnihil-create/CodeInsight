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
  vector<ll> a(N), b(N);
  for (int i=0; i<N; i++) cin >> a[i];
  for (int i=0; i<N; i++) cin >> b[i];
  ll dif1 = 0, dif2 = 0; // a[i]<b[i]の時の差の合計とa[i]>b[i]の時の差の合計
  for (int i=0; i<N; i++) {
    if (a[i]<b[i]) dif1 += (b[i]-a[i])/2;
    else if (a[i]>b[i]) dif2 += a[i]-b[i];
  }
  if (dif1>=dif2) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}